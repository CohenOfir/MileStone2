#include <vector>
#include "ClientHandler.h"
//#include "Solver.h"
//#include "CacheManager.h"
#include "StringReverser.h"
#include "FileCacheManager.h"

class MyTestClientHandler : public ClientHandler {
    Solver<string, string> *solver;
    CacheManager *cm;

public:
    MyTestClientHandler(Solver<string, string> *solve, CacheManager *cacheManager);

    virtual void handleClient(int socket);

    static vector<string> Lexer(string line, char c);
};

