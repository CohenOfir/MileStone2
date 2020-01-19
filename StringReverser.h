//
// Created by ofir on 15/01/2020.
//

#ifndef EX4_STRINGREVERSER_H
#define EX4_STRINGREVERSER_H

#include "Solver.h"
#include <iostream>
#include <algorithm>

using namespace std;

class StringReverser : public Solver<string, string> {
public:
    string solve(string problem);
};

#endif //EX4_STRINGREVERSER_H
