#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stddef.h>
#include <stdio.h>

int main(int argc, char** argv) {

  struct addrinfo *initial_result;
  struct addrinfo *result;

  struct sockaddr_in *four_address;
  struct sockaddr_in6 *six_address;

  char buffer[512];
  
  int retval = getaddrinfo(argv[1],NULL,NULL,&initial_result);

  result = initial_result;
  
  while(result) {
    switch(result->ai_family) {
    case AF_INET:
      four_address = (struct sockaddr_in*)result->ai_addr;
      inet_ntop(AF_INET,&four_address->sin_addr,buffer,512);
      printf("IPv4 address: %s\n",buffer);
      break;
    case AF_INET6:
      six_address = (struct sockaddr_in6*)result->ai_addr;
      inet_ntop(AF_INET6,&six_address->sin6_addr,buffer,512);
      printf("IPv6 address: %s\n",buffer);
      break;
    }
    result = result->ai_next;
  }
  freeaddrinfo(initial_result);
  return(0);  
}
    
  



    
