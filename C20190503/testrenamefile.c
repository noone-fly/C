#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(){
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   char path1[]="/home/pierre/Desktop/tool/C20190503/txt10.txt";
   char newpath[]="/home/pierre/Desktop/txt11.txt";
   extern int errno;
   if(rename(path,newpath)==0){
      printf("the file %s was moved to %s .\n",path,newpath);
   }else{
       printf("can`t move the file %s \n",path);
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }

   if(rename(path1,newpath)==0){
      printf("the file %s was moved to %s .\n",path1,newpath);
   }else{
       printf("can`t move the file %s \n",path1);
      printf("errno: %d\n",errno);
      printf("err  : %s\n",strerror(errno));
   }

}
