#ifndef Server_h
#define Server_h



#include <stdio.h>
//#include <Winsock2.h>
//#include <ws2tcpip.h>
#include <sys/socket.h> 
#include <netinet/in.h>

struct Server
{
    int domain;
    int service;
    int protocol;
    u_long interfaces;
    int port;
    int backlog;

    struct sockaddr_in address;

    int socket;

    void (*launch)(struct Server *server);

    
    
    
};

struct Server server_constructor(int domain, int service, int protocol, u_long interfaces, int port, int backlog, void (*launch) (struct Server *server));



#endif