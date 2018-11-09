#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

static void sighandler(int signo){
  if (signo == SIGINT){
    printf("SIGINT Signal, emergency exit doors opened \n");
    exit(0);
  }
  if (signo == SIGUSR1){
    printf("Parent PID: %d\n",getppid());
    //Dont' exit
  }
}
int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  while (1){
    printf("%d",getpid());
  }
  
  sleep(1);
  return 0;
}
