#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[]) {
  int prime;
  int p[2];
  int i;
  int buf[1];

  if (pipe(p) == -1) {
    fprintf(2, "pipe error\n");
  };

  // The feeder process writes 2 thru 35 to the pipe, then closes the write
  // side.
  for (i = 2; i < 36; i++) {
    buf[0] = i;
    write(p[1], buf, 1);
  }
  close(p[1]);

  if (fork() == 0) {
    while (1) {
      // Make the child's fd 0 reference the feeder's pipe's read-side.
      close(0);
      dup(p[0]);
      close(p[0]);

      if (read(0, buf, 1) == 0) {
        break;
      }
      prime = buf[0];
      printf("%d is prime\n", prime);

      // Create a fresh buffer, writing its fds into p.
      // We already dup'd the fd we needed, so this is ok.
      pipe(p);

      // Sieve inputs.
      while (read(0, buf, 1)) {
        if (buf[0] % prime != 0) {
          write(p[1], buf, 1);
        }
      }

      // Close the fds the process reads from and writes to.
      close(0);
      close(p[1]);

      if (fork() > 0) {
        wait(0);
        break;
      }
    }

  } else {
    wait(0);
  }
}
