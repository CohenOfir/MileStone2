#ifndef EX4_MATRIXCREATOR_H
#define EX4_MATRIXCREATOR_H

#include "Point.h"
#include "MyClientHandler.h"
#include "Matrix.h"

class MatrixCreator {
public:
    MatrixCreator(){}
    Searchable<Point> *createMatrix(vector<string> prob);
    vector<string> split(string line, string delimiter);
    ~MatrixCreator(){}

};


#endif //EX4_MATRIXCREATOR_H
