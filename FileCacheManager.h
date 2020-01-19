#ifndef EX4_FILECACHEMANAGER_H
#define EX4_FILECACHEMANAGER_H

#include "CacheManager.h"
#include <vector>

class FileCacheManager : public CacheManager {
public:
    FileCacheManager();
    bool isInCache(string prob) override;
    string getSolution(string prob) override;
    void setSolution(string prob, string solution) override;
    void saveToDisk(string prob, string solution) override;
    void loadDataMap();
};


#endif //EX4_FILECACHEMANAGER_H
