#ifndef EX4_BFS_H
#define EX4_BFS_H


#include "Searcher.h"
#include <algorithm>
#include <list>
#include <queue>

template<class T>
class BFS : public Searcher<T> {
public:
    string search(Searchable<T> *searchable) {
        vector<State<T> *> visited;
        queue<State<T>*> queue;
        vector<State<T> *> neighbors;
        State<T> *current;

        queue.push(searchable->getInitialState());
        visited.push_back(searchable->getInitialState());

        while (!queue.empty()) {

            current = queue.front();

            if(current->Equals(searchable->getGoalState())){
                string toReturn = searchable->getPath();
                cout << "Number of nodes in trail: "<< searchable->getCounter() << endl;
                cout <<"Total cost for trail: "<<searchable->getGoalState()->getTotalCost()<<endl;
                return toReturn;
            }
            neighbors = searchable->getNeighbors(current);
            queue.pop();

            for (State<T> *neighbor : neighbors) {
                //Neighbors has not been visited, mark as visited and add to queue
                if (!isVisited(visited, neighbor)) {
                    neighbor->setPrevious(current);
                    neighbor->addCost(current->getTotalCost());
                    visited.push_back(neighbor);
                    queue.push(neighbor);
                }
            }
        }
        //no valid route
        return "-1";
    }

    bool isVisited(vector<State<T> *> visited, State<T> *current ){
        for (auto state:visited) {
            if (current->Equals(state)) {
                return true;
            }
        }
        return false;
    }

};


#endif //EX4_BFS_H
