#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
main(){
   extern int errno;
   char *path="/home/pierre/Desktop/tool/C20190503/testmkdirfile";
   if(mkdir(path,0766)==0){
      printf("created the directory %s.\n",path);
   }else{
      printf("can`t create the directory %s.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }
}
