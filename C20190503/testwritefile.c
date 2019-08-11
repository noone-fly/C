#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(){
   int fd;  /**/
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   char s[]="hello, linux.\nI`ve leart C program for two weeks.\n";
   extern int errno;
   fd=open(path,O_WRONLY|O_CREAT);
   if(fd!=-1){
      printf("opened file %s .\n",path);
   }else{
      printf("cant`t open flle  %s.\n",path);
      printf("Errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }

   write(fd,s,sizeof(s));
   close(fd);
   printf("done");
}
