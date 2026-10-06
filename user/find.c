#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
#include "kernel/fcntl.h"

void find(char *path, char *target) {
  char buf[512], *p;
  int fd;
  struct dirent de;
  struct stat st;

  if (stat(path, &st) < 0) {
    fprintf(2, "find: cannot stat %s\n", path);
    exit(1);
  }

  // printf("path: %s\n", path);
  // printf("target: %s\n", target);
  fd = open(path, O_RDONLY); // fd points at path

  while (read(fd, &de, sizeof(de)) == sizeof(de)) {
    if (de.inum == 0) {
      continue;
    }
    // build up absolute path as we recurse
    // printf("before strcpy, buf: %s\n", buf);
    strcpy(buf, path);
    // printf("after strcpy, buf: %s\n", buf);
    p = buf + strlen(buf);
    *p++ = '/';
    memmove(p, de.name, DIRSIZ);
    p[DIRSIZ] = 0;

    // printf("current dirent: %s\n", de.name);
    // printf("current dirent abspath: %s\n", buf);
    if (stat(buf, &st) < 0) {
      printf("find: cannot stat %s\n", de.name);
    };
    switch (st.type) {
    case T_FILE:
      // printf("is file: %s\n", de.name);
      if (strcmp(de.name, target) == 0) {
        printf("%s\n", buf);
      }
      break;

    case T_DIR:
      // Recurse, but not into "." or "..".
      if (strcmp(de.name, ".") != 0 && strcmp(de.name, "..") != 0) {
        // printf("is dir: %s\n", buf);
        // printf("dirent: '%s'\n", de.name);
        // printf("strlen: %d\n", strlen(buf));
        //
        // printf("recursing into %s\n", buf);
        find(buf, target);
      }
      break;
    }
  }
  close(fd);
}

int main(int argc, char *argv[]) { find(argv[1], argv[2]); }
