#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

main(){
   extern int errno;
   char *path="/home/pierre/Desktop/tool/C20190503/tmp.txt";
   if(remove(path)==0){
      printf("Deleted file %s.\n",path);
   }else{
      printf("Can`t create the directory %s.\n",path);
      printf("Errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }
}

