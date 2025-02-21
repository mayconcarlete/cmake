#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1" // Localhost
#define SERVER_PORT 8080 

int main() {
    int sockfd;
    struct sockaddr_in server_addr; 
    char message[] = "Hello, World!"; 
    socklen_t addr_len = sizeof(server_addr); 

    // Create UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Configure server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("invalid address");
        exit(1);
    }

    // Send message to server
    if (sendto(sockfd, message, strlen(message), 0, (struct sockaddr*)&server_addr, addr_len) < 0) {
        perror("sendto failed");
        exit(1);
    }

    printf("Sent 'Hello, World!' to %s:%d\n", SERVER_IP, SERVER_PORT);

    close(sockfd);
    return 0;
}