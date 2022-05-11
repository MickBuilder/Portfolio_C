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

#endif /* */
