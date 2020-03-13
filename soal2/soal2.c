#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <time.h>

void a(char *tgl) {
  char *argv[3] = {"mkdir" , tgl , NULL};
  execv("/bin/mkdir", argv);
}

void b(char *tgl) {

  int status;
  char url[100];
  time_t seconds, time2;
  char tanggal2[100];

while ((wait(&status)) > 0);
        for (int i = 0; i < 20; i++)
        {
          if (fork() == 0)
          {
            chdir(tgl);
            struct tm* info2;
        
            time2 = time(NULL);
            info2 = localtime(&time2);
        
            int seconds = (int)time(NULL);
            seconds = (seconds % 1000) + 100;

            sprintf(url, "https://picsum.photos/%d", seconds);

            char tanggal2[100];
            strftime(tanggal2, 100, "%Y-%m-%d_%H:%M:%S", info2);
            char *argv[] = {"wget", url, "-qO", tanggal2, NULL};
            execv("/usr/bin/wget", argv);
          }
          sleep(5);
}
}
void c(char *tgl) {
  char yes[100];
  strcpy(yes, tgl);
  strcat(yes, ".zip");
  char *argv[5] = {"zip", "-r" , yes , tgl , NULL};
  execv("/bin/zip", argv);
}
int main(int argc, char **argv){

  pid_t child_id, child_id2, child_id3;

  time_t timer;
  struct tm *info;
  char tgl[80];

  time( &timer );
  info = localtime( &timer );
  strftime(tgl,80,"%Y-%m-%d_%X", info);	//read backwards

  child_id = fork();
  if (child_id < 0) {
    exit(EXIT_FAILURE);
  }
  if (child_id == 0) {				//make directory
    a(tgl); }
	else {
    	child_id = wait(NULL);
    	child_id2 = fork();
    	if(child_id2 == 0){				//download and rename file
    	  b(tgl);}
    else{							//zipping folder
      child_id2 = wait(NULL);
      child_id3 = fork();
      if(child_id3 == 0){
        c(tgl);
      }
    else{ child_id3 = wait(NULL);		//remove or delete directory	
          char *argv2[4] = {"rm", "-r" , tgl , NULL};
          execv("/bin/rm", argv2);
      }
    }
  }
}
