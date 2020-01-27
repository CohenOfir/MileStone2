#ifndef EX4_BESTFIRSTSEARCH_H
#define EX4_BESTFIRSTSEARCH_H

#include "Searcher.h"
#include "Point.h"
#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>
#include "StateComperator.h"
template<class T>
class BestFirstSearch : public Searcher<T> {
public:
    string search(Searchable<T>* searchable) override {
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
                    open.push(neighbor);
                    continue;
                }else if (isInClosed(closed, neighbor)){
                    continue;
                }
                else if (current->getTotalCost() + neighbor->getCost() < neighbor->getTotalCost()) {
                    neighbor->setTrailCost(current->getTotalCost() + neighbor->getCost());
                    neighbor->setPrevious(current);
                    open = updatePriorityQ(open);
                }
            }
        }
        searchable->getGoalState()->setTrailCost(-1);
        return to_string(-1);
    }

    bool isInOpen(priority_queue<State<T> *, vector<State<T> *>,  StateComperator<T>> p, State<T> *current) {
        while (!p.empty()) {
            //found state in priority/-queue
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

    priority_queue<State<T>*, vector<State<T> *>,  StateComperator<T>> updatePriorityQ(priority_queue<State<T> *,
            vector<State<T> *>,  StateComperator<T>> p ){
        priority_queue<State<T> *, vector<State<T> *>, StateComperator<T>> newQ;
        while (!p.empty()) {
            newQ.push(p.top());
            p.pop();
        }
        return newQ;
    }

};


#endif //EX4_BESTFIRSTSEARCH_H
