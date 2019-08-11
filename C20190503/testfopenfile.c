#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(){
  FILE fp;
  extern int errno;
  char file[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";

  fp=fopen(file, "r");

  if(fp == NULL){
     printf("can`t open the file %s.\n",file);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
  }else{
     printf("%s was opened . \n",file);
  }

  fclose(fp);
}
