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

    //connecting to server
    int connStatus = connect(sockD , (struct sockaddr*)&servAddr ,sizeof(servAddr));
    if(connStatus == -1){
        printf("Error in Connecting\n");
        exit(0);
    }

    // communication
    char message[255];
    recv(sockD,message,sizeof(message),0);
    printf("\n meesage: %s \n", message);
    close(sockD);
    return 0;
}
