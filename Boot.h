//
// Created by ofir on 21/01/2020.
//

#ifndef EX4_BOOT_H
#define EX4_BOOT_H

#include "Solver.h"
#include "BestFirstSearch.h"
#include "BFS.h"
#include "DFS.h"
#include "Adapter.h"
#include "MyClientHandler.h"
#include "Astar.h"
#include "MyParallelServer.h"
#include "FileCacheManager.h"
#include "Boot.h"

namespace boot {
    class Main {
    public:
        Main(){}
        int main(int port) {
            Solver<Searchable<Point> *, string> *solver = new Adapter(new Astar<Point>());
            CacheManager *cacheManager = new FileCacheManager();
            ClientHandler *clientHandler = new MyClientHandler(solver, cacheManager);
            server_side::Server *server = new MyParallelServer();
            server->open(port, clientHandler);
            return 0;
        }
    };
}


#endif //EX4_BOOT_H
