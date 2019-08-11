#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main(){
   int fd,fd1;
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   extern int errno;
   fd=open(path,O_WRONLY,0766);
   if(fd!=-1){
      printf("opened file %s .\n",path);
   }else{
      printf("can`t open the file %s.\n",path);
      printf("errno: %d\n",errno);
#printf("ERR  : %d\n",perror(errno));
   }

   fd1=open(path,O_WRONLY|O_CREAT,0766);
   if(fd1=-1){
      printf("opened file %s .\n",path);
   }else{
      printf("can`t open the file %s.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %d\n",strerror(errno));

   }
}
