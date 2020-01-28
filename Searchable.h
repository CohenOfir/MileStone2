#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H


#include "State.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

template<class T>
class Searchable {
protected:
    std::vector<State<T> *> matrix;
    State<T> *initialState;
    State<T> *endState;
    int nodesCounter;

public:

    State<T> *getInitialState() { return initialState; }

    State<T> *getGoalState() { return endState; }

    virtual vector<State<T> *> getNeighbors(State<T> *s) = 0;

    string getPath() {
        State<T> *current = getGoalState();
        string path;
        path+=" ,)";
        stringstream stream;
        stream << fixed << setprecision(0) << current->getTotalCost();
        string s = stream.str();
        reverse(s.begin(),s.end());
        path+=s;
        path+="(";
        //iterate from goal to initial state
        while (current->getPrevious() != nullptr) {
            for (State<T> *state:matrix) {
                if (state->getPrevious() != nullptr) {
                    //find father current node
                    if (current->getPrevious()->Equals(state)) {
                        path += current->getState().move(state->getState());
                        path+=" ,)";
                        stringstream stream;
                        stream << fixed << setprecision(0) << current->getPrevious()->getTotalCost();
                        string s = stream.str();
                        reverse(s.begin(),s.end());
                        path+=s;
                        path+="(";
                        nodesCounter++;
                        break;
                    }
                }
            }
            current = current->getPrevious();
            //current state is initial state
            if (current->getPrevious()->Equals(getInitialState())) {
                break;
            }
        }
        //last move
        path += current->getState().move(getInitialState()->getState());
        nodesCounter++;
        reverse(path.begin(), path.end());
        return path;
    }

    int getCounter() {return nodesCounter;}

    ~Searchable() = default;


};



#endif //EX4_SEARCHABLE_H
