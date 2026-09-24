#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  char buf;
  int ping[2];
  int pong[2];

  buf = 'x';

  pipe(ping);
  pipe(pong);

  int pid = fork();
  if (pid == 0) {
    // child
    read(ping[0], &buf, 1);
    printf("%d: received ping\n", getpid());
    write(pong[1], &buf, 1);
    exit(0);
  } else if (pid > 0) {
    // parent
    write(ping[1], &buf, 1);
    read(pong[0], &buf, 1);
    printf("%d: received pong\n", getpid());
    exit(0);
  }
}
