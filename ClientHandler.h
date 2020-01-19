#ifndef EX4_CLIENTHANDLER_H
#define EX4_CLIENTHANDLER_H


class ClientHandler {
public:
    virtual void handleClient(int sockfd) = 0;
};


#endif //EX4_CLIENTHANDLER_H
