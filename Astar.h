#ifndef EX4_ASTAR_H
#define EX4_ASTAR_H


#include <cfloat>
#include "Searcher.h"
#include <set>
#include <stack>
#include <cstring>
#include <queue>
#include "Point.h"
#include "StateComperator.h"
using namespace std;

template<class T>
class Astar : public Searcher<T> {
public:
    string search(Searchable<T>* searchable)  {
        this->searchable = searchable;
        State<T> *current;
        vector<State<T> *> neighbors;
        priority_queue<State<T>*, vector<State<T>*>, StateComperator<T>> open;
        open.push(searchable->getInitialState());
        vector<State<T> *> closed;

        while (!open.empty()) {
            current = open.top();
            open.pop();
            closed.push_back(current);
            //reach goal sate
            if (current->Equals(searchable->getGoalState())) {
                string toReturn = searchable->getPath();
                cout << "Number of nodes in trail: "<< searchable->getCounter() << endl;
                cout <<"Total cost for trail: "<<searchable->getGoalState()->getTotalCost()<<endl;
                return toReturn;
            }
            neighbors = searchable->getNeighbors(current);
            for (State<T> *neighbor : neighbors) {
                //first state
                if (!isInOpen(open, neighbor) && !isInClosed(closed, neighbor)) {
                    neighbor->setPrevious(current);
                    neighbor->addCost(current->getTotalCost());
                    neighbor->setFheuristics(calculateF(neighbor,searchable->getGoalState()));
                    open.push(neighbor);
                    continue;
                    //neighbor is either in open or closed and - can improve path
                } else if (isInClosed(closed, neighbor)){
                    continue;
                }
                else if (current->getTotalCost() + neighbor->getCost() < neighbor->getTotalCost()) {
                    neighbor->setTrailCost(current->getTotalCost() + neighbor->getCost()-1);
                    neighbor->setFheuristics(calculateF(neighbor, searchable->getGoalState()));
                    neighbor->setPrevious(current);
                    open = updatePriorityQ(open);
                }
            }
        }
        searchable->getGoalState()->setTrailCost(-1);
        return "-1";
    }

    bool isInOpen(priority_queue<State<T> *, vector<State<T> *>, StateComperator<T>> p, State<T> *current) {
        while (!p.empty()) {
            //found state in queue
            if (current->Equals(p.top())) { return true; }
            p.pop();
        }
        return false;
    }

    bool isInClosed(vector<State<T>*> closed, State<T>* current) {
        for (auto state:closed) {
            if (current->Equals(state)) {
                return true;
            }
        }
        return false;
    }

    priority_queue<State<T>*, vector<State<T> *>, StateComperator<T>> updatePriorityQ(priority_queue<State<T> *,
            vector<State<T> *>, StateComperator<T>> p ){
        priority_queue<State<T> *, vector<State<T> *>, StateComperator<T>> newQ;
        while (!p.empty()) {
            newQ.push(p.top());
            p.pop();
        }
        return newQ;
    }

    double calculateF(State<T>* state,State<T>* goal) {
        double h = abs(state->getState().getX() - goal->getState().getX()) +
                   abs(state->getState().getY() - goal->getState().getY());
        double g = state->getTotalCost();
        return g + h;
    }

};


#endif //EX4_ASTAR_H
