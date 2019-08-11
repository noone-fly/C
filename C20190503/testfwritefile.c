#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

struct stu{
   char name[10];
   int age;
};

int main(){
   struct stu mystu[3];
   FILE *fp;
   extern int errno;
   char file[]="/home/pierre/Desktop/tool/C20190503/testwritefile.txt";
   int i;

   strcpy(mystu[0].name, "Jim");
   mystu[0].age=13;
   strcpy(mystu[1].name, "Pierre");
   mystu[1].age=32;
   strcpy(mystu[2].name, "pitter");
   mystu[2].age=80;

   fp=fopen(file, "a+b");
   if(fp==NULL){
      printf("can`t open the file %s.\n",file);
      printf("errno: %d\n",errno);
      printf("ERR  : %s\n",strerror(errno));
   }else{
      printf("%s was opened . \n",file);
   }

   for(int a=0; a<3; a++){
      printf("name : %s.\n",mystu[a].name);
      printf("age  : %d.\n",mystu[a].age);
   //   fwrite(&mystu[a], sizeof(mystu), 1, fp);
   }

  
   i=fwrite(mystu, sizeof(mystu), 3, fp);
   printf("%d bit was written. \n", i);
   fclose(fp);
}
  

