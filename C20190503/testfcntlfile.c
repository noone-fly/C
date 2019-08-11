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
   int fd;
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   struct flock fl;
   char s[]="hello, linux.\nI`ve leart C program for two weeks.\n";
   extern int errno;

   fd=open(path, O_WRONLY|O_CREAT);
   if(fd!=-1){
      printf("opened file %s .\n",path);
   }else{
      printf("can`t open file %s \n",path);
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }

   fl.l_type=F_RDLCK;
   fl.l_whence=SEEK_SET;
   fl.l_start=2;
   fl.l_len=10;
   fl.l_pid=15;

   if(fcntl(fd,F_SETLKW,&fl)==0){
      printf("some string fo the file was locketd.\n");
   }else{
      printf("locked error.\n");
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }
   close(fd);
}
