#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <stdlib.h>
#include <string.h>

int server_udp(void);

int server_udp(void){
    int server,client;
    char buffer[1024];
  
    struct sockaddr_in server_addr = { 0 };
//  socklen_t size;
  
    client = socket(AF_INET, SOCK_DGRAM, 0);
    if(client < 0){
         printf("erreur lors de la création de socket\n");
         exit(1);
    }
    printf("socket created\n");
  
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port =htons(11001); // numéro du port est : 15020
      
    if(bind(client, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
        printf("error bind socket\n");
        exit(1);
    }
      
    printf("waiting...\n");
    socklen_t size = sizeof(server_addr);
    while(1){
        if(( recvfrom (client, buffer, (sizeof(buffer) - 1), 0, (struct sockaddr*)&server_addr,  &size)) < 0){
            printf("pas de reception de message");
            exit(1);
        }
        printf("reception d'un message :\n");
        printf("le message recu est : %s \n", buffer); 
    }
    close(client);
 
  
return 0;
}