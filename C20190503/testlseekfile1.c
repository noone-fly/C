#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
int main(){
   int fd;
   char path[]="/home/pierre/Desktop/tool/C20190503/txt1.txt";
   int size;
   char s[100]="";
   extern int errno;
   fd=open(path, O_RDONLY);
   if(fd!=-1){
      printf("opened file %s.\n",path);
   }else{
            printf("cant`t open flle  %s.\n",path); /*文件打开失败*/
      printf("Errno: %d\n",errno); /*显示错误号*/
      printf("ERR  : %s\n",strerror(errno)); /*显示错误信息*/

   }
   
   lseek(fd, 0, SEEK_SET);
   size=read(fd, s, 3);
   printf("%d  :",size);
   printf("%s\n",s);

   lseek(fd, 0, SEEK_CUR);
   size=read(fd, s, 3);
   printf("%d  :",size);
   printf("%s\n",s);


   close(fd);
}
