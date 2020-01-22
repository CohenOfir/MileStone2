#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <vector>

class FileCacheManager : public CacheManager {
    hash<string> hashFunc;
public:
    FileCacheManager(){}
    bool isInCache(string prob);
    string getSolution(string prob);
    void setSolution(string prob, string solution);
    ~FileCacheManager(){}

};


#endif //EX4_FILECACHEMANAGER_H
