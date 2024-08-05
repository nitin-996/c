#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Create socket
    int sockD = socket(AF_INET, SOCK_STREAM, 0);
    if (sockD == -1) {
        printf("Error in creating socket\n");
        exit(0);
    }

    // Setting address
    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(9001);
    servAddr.sin_addr.s_addr = INADDR_ANY;
    
    // Binding
    if (bind(sockD, (struct sockaddr*)&servAddr, sizeof(servAddr)) == -1) {
        printf("Error in binding\n");
        exit(0);
    }

    // Listening
    if (listen(sockD, 5) == -1) {
        printf("Error in listening\n");
        exit(0);
    }
    printf("Listening on port 9001\n");

    // Accepting connection
    socklen_t addr_size = sizeof(servAddr);
    int newSocket = accept(sockD, (struct sockaddr*)&servAddr, &addr_size);
    if (newSocket == -1) {
        printf("Error in accepting\n");
        exit(0);
    }

    // Sending message to client
    char message[] = "This is a message from the server";
    if (send(newSocket, message, strlen(message), 0) == -1) {
        printf("Error in sending message\n");
        exit(0);
    }

    // Closing the sockets
    close(newSocket);
    close(sockD);

    return 0;
}
