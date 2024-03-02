#include "Server.h"


struct Server server_constructor(int domain, int service, int protocol, u_long interfaces, int port, int backlog, void (*launch) (void))
{
    struct Server server;
    server.domain = domain;
    server.service = service;
    server.protocol = protocol;
    server.interfaces = interfaces;
    server.port = port;
    server.backlog = backlog;

    server.address.sin_family = domain;
    server.address.sin_port = htons(port);
    server.address.sin_addr.s_addr = htonl(interfaces);

    return server;

}