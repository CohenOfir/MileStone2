//
// Created by ofir on 19/01/2020.
//

#include "Adapter.h"

string Adapter::solve(Searchable<Point>* p) {
    return searcher->search(p);
}