#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(){
   int fd, fd2, size, i=1;
   char path[]="/home/pierre/Desktop/tool/C20190503/readfile.txt";
   char newpath[]="/home/pierre/Desktop/tool/C20190503/writefile.txt";
   char buf[100];
   extern int errno;
   
   fd=open(path,O_RDONLY|O_CREAT);
   fd2=open(newpath,O_WRONLY|O_CREAT);
   if(fd!=-1){
      printf("opened file %s .\n",path);
   }else{
      printf("can`t open file %s \n",path);
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }

   for(;i!=0;){
      i=read(fd, buf, sizeof(buf));
      printf("%d",i);
      printf("%s",buf);
      if(i==-1){
         break;
      }else{
         write(fd2, buf, sizeof(buf));
      }
   }
   close(fd);
   close(fd2);
}
