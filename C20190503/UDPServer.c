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

#define LOCALPORT 4567

int main(int argc, char *argv[])
{
   int mysock, len;
   struct sockaddr_in addr;
   char msg[256];
   int i=0;
   int addr_len = sizeof(struct sockaddr_in);

   /* 建立socket，注意必须是SOCK_DGRAM */
   if(( mysock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) 
   {
      perror("error");
      exit(1);
   }
   else
   {
      printf("socket created. \n");
      printf("socket id: %d \n",mysock);
   }

   
   /* 填写sockaddr_in 结构 */
   bzero(&addr, sizeof(addr)); /**/
   addr.sin_family = AF_INET;  /**/
   addr.sin_port = htons(LOCALPORT);
   addr.sin_addr.s_addr = htonl(INADDR_ANY); // 接收任意IP发来的数据

   /* 绑定socket */
   if( bind(mysock, (struct sockaddr *)&addr, sizeof(addr)) < 0 )
   {
      perror("connect");
      exit(1);
   }
   else
   {
      printf("bind ok. \n");
      printf("local port : %d \n", LOCALPORT);
   }

   while(1)
   {
      bzero(msg, sizeof(msg));
      len = recvfrom(mysock, msg, sizeof(msg), 0, (struct sockaddr *)&addr, &addr_len); 
      /* 显示client端的网络地址和收到的字符串消息 */
      printf("%d: ",i);
      i++;
      printf("Received message from client address : %s \n", inet_ntoa(addr.sin_addr));
      printf("              Received message length : %d \n", len);
      printf("                  Received message is : %s \n", msg);

      /* 将收到的字符串消息返回给client端 */
      sendto(mysock, msg, len, 0, (struct sockaddr *)&addr, addr_len);
   }
}
