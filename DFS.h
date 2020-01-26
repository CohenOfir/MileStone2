//
// Created by ofir on 19/01/2020.
//

#ifndef EX4_DFS_H
#define EX4_DFS_H

#include "Searcher.h"
#include <stack>
using namespace std;

template <class T>
class DFS : public Searcher<T> {
public:
    string search(Searchable<T> *searchable) {
        vector<State<T> *> visited;
        stack<State<T> *> stack;
        vector<State<T> *> neighbors;
        State<T> *current;

        stack.push(searchable->getInitialState());

        while (!stack.empty()) {
            current = stack.top();
            stack.pop();

            if (!inVisited(visited, current)) {
                visited.push_back(current);
            }

            if(current->Equals(searchable->getGoalState())) {
                string toReturn = searchable->getPath();
                cout << "Number of nodes in trail: "<< searchable->getCounter() << endl;
                cout <<"Total cost for trail: "<<searchable->getGoalState()->getTotalCost()<<endl;
                return toReturn;
            }

            neighbors = searchable->getNeighbors(current);
            for (State<T> *neighbor : neighbors) {
                //if a neighbors has not been visited then mark as visited and add to queue list
                if (!inVisited(visited,neighbor)) {
                    neighbor->setPrevious(current);
                    neighbor->addCost(current->getTotalCost());
                    stack.push(neighbor);
                }
            }
        }
        return "-1";
    }



    bool inVisited(vector<State<T> *> visited,State<T> *current ){
        for (auto state:visited) {
            if (current->Equals(state)) {
                return true;
            }
        }
        return false;
    }
};


#endif //EX4_DFS_H
