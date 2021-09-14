#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include <arpa/inet.h>
#include <memory.h>
#include <stdio.h>
#include <string>

int main(int argc, char *argv[]){
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if(s < 0){ perror("Error calling socket"); return 0;}

    struct sockaddr_in peer;
    peer.sin_family = AF_INET;
    peer.sin_port = htons(18666);
    peer.sin_addr.s_addr = inet_addr(argv[1]);
    int result = connect(s, (struct sockaddr *)&peer, sizeof(peer));
    if(result){perror("Error calling connect"); return 0;}

    char buff[] = "Message from client!";
    result = send(s, argv[2], sizeof(argv[2]), 0);
    if(result <= 0){perror("Error calling send"); return 0;}
    
    if(shutdown(s, 1) < 0){perror("Error calling shutdown"); return 0;}

    fd_set readmask; 
    fd_set allreads;
    FD_ZERO(&allreads);
    FD_SET(0, &allreads);
    FD_SET(s, &allreads);
    for(;;){
        readmask = allreads;
        if(select(s + 1, &readmask, NULL, NULL, NULL) <= 0){perror("Error calling select"); return 0;}
        if(FD_ISSET(s, &readmask)){
            char buffer[20];
            memset(buffer, 0, 20*sizeof(char));
            int result = recv(s, buffer, sizeof(buffer) - 1, 0);
            if(result < 0){perror("Error calling recv"); return 0;}
            if(result == 0){perror("Server disconnected"); return 0;}
            if(strncmp(buffer, "Hi, dear", 9) == 0){printf("Got answer. Succes\n");}
            else{perror("Wrong answer");}
        }
        if(FD_ISSET(0, &readmask)){
            printf("No server response");
            return 0;
        }
    }
    return 0;
}