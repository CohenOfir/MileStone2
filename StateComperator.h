//
// Created by ofir on 22/01/2020.
//

#ifndef EX4_STATECOMPERATOR_H
#define EX4_STATECOMPERATOR_H
#include "State.h"

template<class T>
class StateComperator {
public:
    StateComperator(){};
    bool operator()(State<T>* left, State<T>* right) {
        return (left->getFheuristics()) > (right->getFheuristics());
    }
};


#endif //EX4_STATECOMPERATOR_H
