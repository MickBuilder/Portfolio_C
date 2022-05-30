#ifndef _TCP_CLIENT_H
#define _TCP_CLIENT_H

#ifdef WIN32

#include <winsock2.h>

#elif defined (linux)

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#define close(socket) close_socket(socket)

typedef int SOCKET
typedef struct sockaddr_in SOCKADDR_IN

#else 

#error Not deined for this plaatform

#endif

#define PORT 9999
#define HOSTNAME "bananabox.ddns.net"
#define BUFFER_SIZE 1024

static void init();
static void end();
static int init_connection(const char *hostname);
static void end_connection(int socket_fd);
static void send_to_server(int socket_fd, const char *message);
static int receive_from_server(int socket_fd, char *buffer);

#endif /* */
