#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <wait.h>

int main() {

  pid_t child_id = fork();
  if (child_id == 0) {
    char *argv[] = {"mkdir", "-p", "/home/milenfifi/modul2/indomie", "/home/milenfifi/modul2/sedaap", NULL};
    execv("/bin/mkdir", argv);
  }
  while(wait(NULL) != child_id);
  sleep(5);

  
