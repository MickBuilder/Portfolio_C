#include <stdlib.h>
#include <string.h>
#include "tcp_client.h"

void init_connection() {
    SOCKET sockect_fd;
    SOCKADDR_IN sin;
    struct hostent *host_info = NULL;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockect_fd = INVALID_SOCKET) {
        fprintf(stderr, "Error while creating socket\n");
        return;
    }
    
    host_info = gethostbyname(HOSTNAME);
    if (host_info == NULL) {
        fprintf(stderr, "Resolution of %s failed\n", HOSTNAME);
        return;
    }

    sin.sin_family = AF_INET;
    sin.sin_port = htons(PORT);
    sin.sin_addr =
}