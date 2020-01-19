#ifndef EX4_MYSERIALSERVER_H
#define EX4_MYSERIALSERVER_H

#include <thread>
#include "Server.h"
#include <stdio.h>
#include <string>
#include <functional>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <cstring>
#include "ClientHandler.h"

using namespace std;

extern bool shouldStop;

class MySerialServer : public server_side::Server {
public:
    MySerialServer();

    ~MySerialServer();

    void open(int port, ClientHandler *c);

    void stop();

    static void clientsLoop(ClientHandler *, int, sockaddr_in);
};


#endif //EX4_MYSERIALSERVER_H
