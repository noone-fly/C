#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(){
   int fd;
   char path[]="/home/pierre/Desktop/tool/C20190503/fd.txt";
   int size;
   char s[100]="";
   extern int errno;
   fd=open(path, O_RDONLY|O_CREAT);
   printf("fd: %d\n",fd);
   if(fd!=-1){
      printf("opened file %s.\n",path);
   }else{
      printf("cannot openfile %s \n",path);
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }
}
