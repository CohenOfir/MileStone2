//
// Created by ofir on 15/01/2020.
//

#include "StringReverser.h"

string StringReverser::solve(string problem) {
    string solution = problem;
    reverse(solution.begin(),solution.end());
    return solution;
}