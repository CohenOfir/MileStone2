#ifndef EX4_MYPARALLELSERVER_H
#define EX4_MYPARALLELSERVER_H

#include <vector>
#include "Server.h"
#include "ThreadData.h"
#include <pthread.h>
#include <stack>
using namespace std;

class MyParallelServer : public server_side::Server {
private:
    ThreadData *info = new ThreadData();
    stack<pthread_t> threads;

public:
    void open(int port, ClientHandler *c) override;
    void stop() override;
    void start(int server_sock, ClientHandler *ch);
   ~MyParallelServer() {delete info;}
};



#endif //EX4_MYPARALLELSERVER_H
