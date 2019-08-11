#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
main(){
   extern int errno;
   char path[]="mytemp-XXXXXX";
   if(mkstemp(path)!=-1){
      printf("created temp file %s.\n",path);
   }else{
      printf("can`t create temp file %s.\n",path);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }
}
