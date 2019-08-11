#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
main(){
   extern int errno;
   char *path = "/home/pierre/Desktop/tool/C20190503/tmp.txt";
   if(creat(path,0766)==-1){
      printf("can`t create the file %s.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }else{
      printf("created file %s.\n",path);
   }
}
