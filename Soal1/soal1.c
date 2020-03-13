#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    printf("argumen salah\n");
    exit(EXIT_FAILURE);
  }
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  int f1, f2, f3;
  time_t rawtime;
  struct tm * tm;

  while (1) {
    f1 = f2 = f3 = 0;
    rawtime = time(0);
    tm = localtime(&rawtime);
    if (tm->tm_sec == atoi(argv[1])) {
      f1 = 1;
    }
    if (tm->tm_min == atoi(argv[2])) {
      f2 = 1;
    }
    if (tm->tm_hour == atoi(argv[3])) {
      f3 = 1;
    }
    if (f1 == 1 && f2 == 1 && f3 == 1) {

      pid_t child_id;

      child_id = fork();

      char *argf[4] = {"bash", argv[4], NULL};

      if (child_id == 0) {
        execv("/bin/bash", argf);
        sleep(1);
      }
    }
  }
}
