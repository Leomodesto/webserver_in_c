#ifndef Server_h
#define Server_h



#include <stdio.h>
#include <Winsock2.h>
struct Server
{
    int domain;
    int service;
    int protocol;
    u_long interfaces;
    int port;
    int backlog;

    struct sockaddr_in address;

    void (*launch)(void);


    
    
};

struct Server server_constructor(int domain, int service, int protocol, u_long interfaces, int port, int backlog, void (*launch) (void));



#endif