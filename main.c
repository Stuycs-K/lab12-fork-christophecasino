#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>

int rand_int(){
  FILE *fd = open("/dev/random", O_RDONLY, 0);
  if(fd == -1){
    printf("%s\n", strerror(errno));
    exit(1);
  }
  uint arr[1];
  read(fd, arr, 4);
  arr[0] = arr[0] % 5 + 1;
  close(fd);
  return arr[0];
}

int main(){
  int pid_var = getpid();
  int num = rand_int();
  pid_t p;
  p = fork();
  if(p<0){
    perror("fork fail");
    exit(1);
  } else if ( p == 0){
      printf("%d %d seconds\n", pid_var, num);
      sleep(num);
      printf("%d finished after %d seconds", pid_var, num);
  }else{
      printf("not done\n");
  }
  return 0;
}