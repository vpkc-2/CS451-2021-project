#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int client_udp(void);

int client_udp(void){
  
    char buffer[1024]="coucou";
  
    struct sockaddr_in sin;
  
    sin.sin_family = AF_INET;
    sin.sin_port = htons(11001);
    sin.sin_addr.s_addr = inet_addr("127.0.0.1");
  
    int client = socket(AF_INET, SOCK_DGRAM, 0);
    if( client < 0){
        printf("error client\n");
        exit(1);
    }
      
    printf("client created\n");
    socklen_t to = sizeof(sin);
    strcpy(buffer,"yo mec  ");
    while(1){
    if( (sendto(client, buffer, strlen(buffer), 0, (struct sockaddr*)&sin, to))< 0){
        printf(" error sendto\n");
        exit(1);
    }
    printf("le message : %s a ete envoye\n",buffer);
    }
    close(client);
  
return 0;
}