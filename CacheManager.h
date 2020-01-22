#ifndef EX4_CACHEMANAGER_H
#define EX4_CACHEMANAGER_H

#include <string>
#include <map>

using namespace std;

class CacheManager {
public:
    virtual bool isInCache(string prob) = 0;
    virtual string getSolution(string prob) = 0;
    virtual void setSolution(string prob, string solution) = 0;
    virtual ~CacheManager() = default;
};


#endif //EX4_CACHEMANAGER_H
