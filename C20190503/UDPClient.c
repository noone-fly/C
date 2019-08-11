#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <string.h>

#define REMOTEPORT 4567
#define REMOTEIP "127.0.0.1"

int main(int argc, char *argv[])
{
   int s, len;
   struct sockaddr_in addr;
   int addr_len = sizeof(struct sockaddr_in);
   char msg[256];
   int i=0;

   if(( s = socket(AF_INET, SOCK_DGRAM, 0)) < 0) /* 建立socket，注意必须是SOCK_DGRAM */
   {
      perror("error");
      exit(1);
   }
   else
   {
      printf("socket created. \n");
      printf("socket id: %d \n",s);
      printf("remote ip: %s \n",REMOTEIP);
      printf("remote port: %d\n",REMOTEPORT);
   }

   
   /* 填写sockaddr_in 结构 */
   bzero(&addr, sizeof(addr)); /**/
   addr.sin_family = AF_INET;  /**/
   addr.sin_port = htons(REMOTEPORT);
   addr.sin_addr.s_addr = inet_addr(REMOTEIP);

   while(1)
   {
      bzero(msg, sizeof(msg));
      printf("Please enter a string to send to server: \n");
      /* 从标准输入设备取得字符串*/
      len = read(STDIN_FILENO, msg, sizeof(msg));

      /* 将字符串传送给server端*/
      sendto(s, msg, len, 0, (struct sockaddr *)&addr, addr_len);
      printf("\n Input message is : %s \n", msg);

      /* 接收server端返回的字符串*/
      len = recvfrom(s, msg, sizeof(msg), 0, (struct sockaddr *)&addr, &addr_len); 
      printf(" %d ",i);
      i++;
      printf("Received message from server : %s \n", msg);
   }
   return 0;
}
