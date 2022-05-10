
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include <stdlib.h>

int main(){
    int lfd = socket(AF_INET, SOCK_STREAM, 0);

    if(lfd == -1){
        perror("socket");
        exit(-1);
    }

    struct sockaddr_in saddr;
    saddr.sin_family = AF_INET;
    // inet_pton(AF_INET, "127.0.0.1", saddr.sin_addr.s_addr);
    saddr.sin_addr.s_addr = INADDR_ANY;
    saddr.sin_port = htons(9999);
    
    int ret = bind(lfd, (struct sockaddr *) &saddr, sizeof(saddr));

    if(ret == -1){
        perror("bind");
        exit(-1);
    }

    ret = listen(lfd, 8);

    if(ret == -1){
        perror("listen");
         exit(-1);
    }

    struct sockaddr_in clientaddr;
    socklen_t len = sizeof(clientaddr);
    int cfd = accept(lfd, (struct sockaddr*) &clientaddr, &len);

    if(cfd == -1){
        perror("accept");
         exit(-1);
    }

    char clientIP[16];
    inet_ntop(AF_INET, &clientaddr.sin_addr.s_addr, clientIP, sizeof(clientIP));
    unsigned short clientPort = ntohs(clientaddr.sin_port);
    printf("client ip is %s, port is %d\n", clientIP, clientPort);

    char recvBuff[1024] = {0};
    while(1){
        int num = read(cfd, recvBuff, sizeof(recvBuff));
        if(num == -1){
            perror("read");
            exit(-1);
        }else if (num > 0){
            printf("recv client data: %s\n", recvBuff);
        }else if(num == 0){
            printf("clinet closed...");
            break;
        }
        char * data = "hello, iam server";
        write(cfd, data, strlen(data));
    }
    

    close(cfd);
    close(lfd);

    return 0;
}