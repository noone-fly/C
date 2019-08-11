#include <stdio.h>
#include <netdb.h>

int main()
{
   struct servent *ser;
   while(ser=getservent())
   {
      printf("name : %s    ", ser->s_name);
      printf("port : %d    ", ntohs(ser->s_port));
      printf("protocol : %s    ", ser->s_proto);
      printf("alias : %s\n", ser->s_aliases[0]);
   }
}
