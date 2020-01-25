//
// Created by ofir on 17/01/2020.
//

#ifndef EX4_SEARCHER_H
#define EX4_SEARCHER_H


#include <string>
#include "Searchable.h"
template <class T>
class Searcher {
protected:
    Searchable<T>* searchable;

public:
    virtual string search (Searchable<T>* searchable) = 0;
    virtual ~Searcher(){ delete searchable;}

};

#endif //EX4_SEARCHER_H
