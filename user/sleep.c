#include "kernel/types.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int ticks;
  int ret;

  if (argc == 0) {
    fprintf(2, "usage: sleep ticks\n");
    exit(1);
  }

  ticks = atoi(argv[1]);
  ret = sleep(ticks);
  exit(ret);
}
