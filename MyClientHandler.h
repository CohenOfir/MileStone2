#ifndef EX4_MYCLIENTHANDLER_H
#define EX4_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"
#include "Searchable.h"
#include "Point.h"

class MyClientHandler : public ClientHandler{
private:
    Solver<Searchable<Point>*,string>* solver;
    CacheManager* cacheManager;
public:
    MyClientHandler(Solver<Searchable<Point>*,string>* solver,CacheManager* cacheManager);
    void handleClient(int socketId);
    //Searchable<Point>* makeMatrix(vector<string> tempProb);
    //vector<string> split(string line, string delimiter);
};

#endif //EX4_MYCLIENTHANDLER_H
