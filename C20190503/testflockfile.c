#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/file.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(){
   int fd,i;
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   extern int errno;
   fd=open(path,O_WRONLY|O_CREAT);
   if(fd!=-1){
      printf("opened file %s  .\n",path);
      printf("please input a number to lock the file.\n");
      scanf("%d",&i);

      if(flock(fd,LOCK_EX)==0){
         printf("the file was locked.\n");
      }else{
         printf("the file was not locked.\n");
      }

      printf("please input a number to unlock the file.\n");
      scanf("%d",&i);
      if(flock(fd,LOCK_UN)==0){
         printf("the file was unlocked.\n");
      }else{
         printf("the file was not unlocked.\n");
      }

      close(fd);
   }else{
      printf("can`t open file %s \n",path);
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }
}
