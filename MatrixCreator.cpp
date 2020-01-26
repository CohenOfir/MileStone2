#include "MatrixCreator.h"

vector<string> MatrixCreator::split(string line, string delimiter) {
    vector<string> data;
    size_t position;
    while ((position = line.find(delimiter)) != string::npos) {
        if (!line.substr(0, position).empty()) {
            data.push_back(line.substr(0, position));
        }
        line.erase(0, position + delimiter.length());
    }
    data.push_back(line.substr(0, position));
    return data;
}

Searchable<Point> *MatrixCreator::createMatrix(vector<string> prob) {
    vector<State<Point> *> searchable;
    vector<string> cutVector;


    cutVector = split(prob[prob.size() - 2], ",");
    State<Point> *initialState = new State<Point>(Point(stoi(cutVector[0]), stoi(cutVector[1])), 0);
    cutVector = split(prob[prob.size() - 1], ",");
    State<Point> *goalState = new State<Point>(Point(stoi(cutVector[0]), stoi(cutVector[1])), 0);

    int size = prob.size() - 2;
    int col = split(prob[0], ",").size();

    for (int i = 0; i < size; ++i) {
        cutVector = split(prob[i], ",");
        for (int j = 0; j < col; ++j) {
            //set initial state cost
            if (i == initialState->getState().getX() && j == initialState->getState().getY()) {
                initialState->setCost(stod(cutVector[j]));
                searchable.push_back(initialState);
                //set endState state cost
            } else if (i == goalState->getState().getX() && j == goalState->getState().getY()) {
                goalState->setCost(stod(cutVector[j]));
                searchable.push_back(goalState);
                //make states
            } else {
                searchable.push_back(new State<Point>(Point(i, j), stoi(cutVector[j])));
            }
        }
    }
    Searchable<Point> *matrix = new Matrix(searchable, initialState, goalState);
    return matrix;
}

