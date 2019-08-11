#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char *argv[]){
   struct hostent *host;
   char hostname[]="www.163.com";
   char hostname2[]="www.ld5r6f.com";
   struct in_addr in;
   struct sockaddr_in addr_in;
   extern int h_errno;

   if((host=gethostbyname(hostname))!=NULL)
   {
      memcpy(&addr_in.sin_addr.s_addr, host->h_addr, 4);
      in.s_addr = addr_in.sin_addr.s_addr;
      printf("Domain name: %s\n", hostname);
      printf("IP length  : %d\n", host->h_length);
      printf("Type       : %d\n", host->h_addrtype);
      printf("IP         : %s\n", inet_ntoa(in));
   }
   else
   {
      printf("Domain name: %s.\n", hostname);
      printf("errno: %d\n", h_errno);
      printf("ERR  : %s\n", hstrerror(h_errno));
   }

   if((host=gethostbyname(hostname2))!=NULL){
      memcpy(&addr_in.sin_addr.s_addr, host->h_addr, 4);
      in.s_addr = addr_in.sin_addr.s_addr;
      printf("Domain name: %s\n", hostname2);
      printf("IP length  : %d\n", host->h_length);
      printf("Type       : %d\n", host->h_addrtype);
      printf("IP         : %s\n", inet_ntoa(in));
   }else{
      printf("Domain name: %s.\n", hostname2);
      printf("errno: %d\n", h_errno);
      printf("ERR  : %s\n", hstrerror(h_errno));
   }
}
