#include "Server.h"
#include <stdio.h>
#include <stdlib.h>

struct Server server_constructor(int domain, int service, int protocol, u_long interfaces, int port, int backlog, void (*launch) (struct Server *server))
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

    server.socket = socket (domain, service, protocol);

    if(server.socket == 0){

        perror("Falha ao conectar o socket...\n");
        exit(1); /*<- 1 representa falha ao sair do programa - importar stdlib*/
    }


    if ((bind(server.socket, (struct sockaddr *)&server.address, sizeof(server.address))) < 0)
    {
        perror("Falha ao bindar o socket...\n");
        exit(1);
    }

    if ((listen(server.socket, server.backlog)) < 0)
    {
        perror("Falha ao comecar escutar...\n");
        exit(1);
    }

    server.launch = launch;

    return server;

}