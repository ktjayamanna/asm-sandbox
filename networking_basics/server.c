#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_socket;
    server_socket = socket(AF_INET, 
        SOCK_STREAM, 
        0
    );
    if (server_socket == -1) {
        printf("There was an error creating the socket\n\n");
        exit(1);
    } else {
        printf("Socket created\n");
    }
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002);
    server_address.sin_addr.s_addr = INADDR_ANY;
    if (bind(
        server_socket, 
        (struct sockaddr *) &server_address, 
        sizeof(server_address)
    ) == -1) {
        printf("There was an error binding the socket\n\n");
        exit(1);
    } else {
        printf("Socket bound\n");
    }
    int num_clients = 0;
    if (listen(server_socket, num_clients) == -1) {
        printf("There was an error listening\n\n");
        exit(1);
    } else {
        printf("Listening\n");
    }
    int client_socket;
    client_socket = accept(
        server_socket, 
        NULL, 
        NULL
    );
    if (client_socket == -1) {
        printf("There was an error accepting the connection\n\n");
        exit(1);
    } else {
        printf("Connection accepted\n");
    }
    char server_response[] = "You have reached the server\n";
    send(
        client_socket, 
        server_response, 
        sizeof(server_response), 
        0
    );
    close(server_socket);


    return 0;

}