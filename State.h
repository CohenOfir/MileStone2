//
// Created by ofir on 17/01/2020.
//

#ifndef EX4_STATE_H
#define EX4_STATE_H


#include <vector>
#include <cfloat>

using namespace std;

template<class T>
class State {
private:
    T state;
    double cost;
    double totalCost;
    double Fheuristics;
    State<T> *previous;


public:
    State<T>(T state, double cost) : state(state), cost(cost), totalCost(cost), previous(nullptr), Fheuristics(FLT_MAX) {}

    double getCost() const { return cost; }

    bool Equals(State<T> *s) { return this->state == s->state; }

    void setPrevious(State<T> *prev) { this->previous = prev; }

    void addCost(double c) { totalCost += c; }

    double getTotalCost() { return totalCost; }

    void setTrailCost(double cost) { this->totalCost = cost; }

    T getState() { return state; }

    void setCost(double cost) {
        this->cost = cost;
        this->totalCost = cost;
    }

    State<T>* getPrevious() { return previous; }
    void setFheuristics(double f){
        this->Fheuristics = f;
    }
    double getFheuristics(){
        return Fheuristics;
    }
};

#endif //EX4_STATE_H
