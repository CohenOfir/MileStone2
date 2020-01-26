#include "Matrix.h"
Matrix::Matrix(std::vector<State<Point>*> matrix, State<Point>* initialState, State<Point>* endState) {
    this->matrix = matrix;
    this->initialState = initialState;
    this->endState = endState;
    this->nodesCounter=0;
}

vector<State<Point>*> Matrix::getNeighbors(State<Point>* s){
    vector<State<Point>*> neighbors;
    for (State<Point>* state : matrix) {
        if (state->getState().isLeftNeighbor(s->getState()) || state->getState().isRightNeighbor(s->getState())
            || state->getState().isUpNeighbor(s->getState()) || state->getState().isDownNeighbor(s->getState())) {
            if (state->getCost() != -1) {
                neighbors.push_back(state);
            }
        }
    }
    return neighbors;
}

Matrix::~Matrix(){
    for (auto state: matrix){
        delete state;
    }
}

