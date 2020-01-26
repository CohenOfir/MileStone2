//
// Created by ofir on 19/01/2020.
//

#ifndef EX4_MATRIX_H
#define EX4_MATRIX_H


#include "Searchable.h"
#include "Point.h"

class Matrix : public Searchable<Point>{

public:
    Matrix(vector<State<Point>*> matrix, State<Point>* initialState, State<Point>* endState);
    vector<State<Point>*> getNeighbors(State<Point>* s) override;
    int getCounter() {return nodesCounter;}
    ~Matrix();
};


#endif //EX4_MATRIX_H
