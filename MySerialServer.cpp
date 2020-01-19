//
// Created by ofir on 15/01/2020.
//

#include "MySerialServer.h"

bool shouldStop = false;

MySerialServer::MySerialServer() {

}

void MySerialServer::open(int port, ClientHandler *c) {
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        cout << "could not open socket" << endl;
        exit(1);
    }
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port);

    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        cout << "could not bind the socket to an IP" << endl;
        exit(1);
    }
    thread serialThread(clientsLoop, c, socketfd, address);
    serialThread.join();


};

void MySerialServer::stop() {
    shouldStop = true;
}

void MySerialServer::clientsLoop(ClientHandler *c, int socketfd, sockaddr_in address) {
    while (!shouldStop) {
        if (listen(socketfd, 5) == -1) {
            cerr << "Error during listening command" << endl;
            exit(1);
        } else {
            cout << "Server is now listening ..." << endl;
        }
        int addrlen = sizeof(address);
        //time out , if there is no connection for 10 seconds.
        struct timeval tv;
        tv.tv_sec = 10;
        setsockopt(socketfd, SOL_SOCKET, SO_RCVTIMEO, (const char *) &tv, sizeof tv);
        // accepting a client
        int client_socket = accept(socketfd, (struct sockaddr *) &address, (socklen_t *) &addrlen);

        cout << "server is now Connected" << endl;

        if (client_socket == -1) {
            std::cerr << "Error accepting client" << std::endl;
            break;
        }

        c->handleClient(client_socket);
        //the client socket is closed after handling the client.
        close(client_socket);
    }
}