#include <stdio.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <wchar.h>
#include <unistd.h> 
#include <string.h> 

#define PORT 3000

int main() 
{
    int sock = 0, valread; 
    struct sockaddr_in serv_addr; 
    char *hello = "안녕"; 
    // wchar_t buffer[1024] = {0}; 
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
    { 
        printf("\n Socket creation error \n"); 
        return -1; 
    } 
   
    serv_addr.sin_family = AF_INET; 
    serv_addr.sin_port = htons(PORT); 
       
    // Convert IPv4 and IPv6 addresses from text to binary form 
    if(inet_pton(AF_INET, "192.168.10.131", &serv_addr.sin_addr)<=0)  
    { 
        printf("\nInvalid address/ Address not supported \n"); 
        return -1; 
    } 
   
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    { 
        printf("\nConnection Failed \n"); 
        return -1; 
    } 
    send(sock , hello , strlen(hello) , 0 ); 
    printf("Hello message sent\n"); 
    // valread = read(sock , buffer, 1024); 
    // printf("%s\n",buffer); 
    return 0; 
}