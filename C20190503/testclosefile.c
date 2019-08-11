#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(){
   int fd;
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   extern int errno;
   fd=open(path,O_WRONLY|O_CREAT,0766);
   if(fd!=-1){
      printf("opened file %s .\n",path);
   }else{
      printf("can`t open the file %s.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }

   if(close(fd)==0){
      printf("close.\n");
   }else{
      printf("close file %s error.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }

   if(close(1156)==0){
      printf("close.\n");
   }else{
      printf("close the file %s error.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }
}
