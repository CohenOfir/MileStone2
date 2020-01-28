#ifndef EX4_THREADDATA_H
#define EX4_THREADDATA_H


#include "ClientHandler.h"

class ThreadData {
public:
    int socket;
    ThreadData(){}
    ClientHandler *ch;
};


#endif //EX4_THREADDATA_H
