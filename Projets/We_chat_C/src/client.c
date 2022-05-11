#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tcp_client.h"

static void init() {
#ifdef WIN32
    WSADATA wsaData;
    int error = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (error != 0) {
        printf("WSAStartup failed: %d\n", error);
        exit(1);
    }
#elif defined (linux)
    // nothing to do
#else
    #error Not deined for this plaatform
#endif
}

void end() {
#ifdef WIN32
    WSACleanup();
#elif defined (linux)
    // nothing to do
#else  
    #error Not deined for this plaatform
#endif
}

static int init_connection(const char *hostname) {
    SOCKET socket_fd;
    SOCKADDR_IN sin;
    struct hostent *host_info = NULL;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd = INVALID_SOCKET) {
        fprintf(stderr, "Error while creating socket\n");
        return;
    }
    
    host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        fprintf(stderr, "Resolution of %s failed\n", hostname);
        return;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr = *((struct in_addr *)host_info->h_addr);

    if (connect(socket_fd, (SOCKADDR_IN *)&sin, sizeof(sin)) == SOCKET_ERROR) {
        fprintf(stderr, "Connection to %s:%d failed\n", hostname, PORT);
        return;
    }

    printf("Connection to %s:%d established\n", hostname, PORT);
}

static void end_connection(int socket_fd) {
    close(socket_fd);
    printf("Connection closed\n");
}

static void send_to_server(int socket_fd, const char *message) {
    if (send(socket_fd, message, strlen(message), 0) < 0) {
        fprintf(stderr, "Sending failed\n");
        return;
    }
}

static int receive_from_server(int socket_fd, char *buffer) {
    int nb_bytes = 0;
    if ((nb_bytes = recv(socket_fd, buffer, BUFFER_SIZE, 0)) < 0) {
        fprintf(stderr, "Receiving failed\n");
        return -1;
    }

    buffer[nb_bytes] = '\0';

    return nb_bytes;
}