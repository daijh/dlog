#include "dlog.h"

#include <unistd.h>

int main(int argc, char** argv) {
  int loop = 10;
  while (loop--) {
    sleep(1);
    DLOG("hello world!\n");
  }

  return 0;
}
