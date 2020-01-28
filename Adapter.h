#ifndef EX4_ADAPTER_H
#define EX4_ADAPTER_H


#include "Solver.h"
#include "Searcher.h"
#include "Point.h"
#include "Solver.h"
#include "Searcher.h"
#include "Point.h"


class Adapter : public Solver<Searchable<Point>*,string>{
private:
    Searcher<Point>* searcher;
public:
    Adapter(Searcher<Point>* searcher) {
        this->searcher = searcher;

    }
    string solve(Searchable<Point>* p);
    ~Adapter(){ delete searcher;}
};


#endif //EX4_ADAPTER_H
