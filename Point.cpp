//
// Created by ofir on 19/01/2020.
//

#include "Point.h"

Point::Point(int x, int y) {
    this->x= x;
    this->y =y;
}

int Point::getX() {
    return x;
}

int Point::getY() {
    return y;
}

bool Point::operator==(Point other) {
    return this->x == other.x && this->y == other.y;
}

bool Point::isLeftNeighbor(Point other) {
    return this->x == other.getX() && this->y == (other.getY() -1);
}

bool Point::isRightNeighbor(Point other) {
    return this->x == other.getX() && this->y == (other.getY() +1);
}

bool Point::isUpNeighbor(Point other) {
    return this->x == (other.getX() - 1) && this->y == other.getY();
}

bool Point::isDownNeighbor(Point other) {
    return this->x == (other.getX() + 1) && this->y == other.getY();
}

string Point::move(Point other) {
    if (this->x == other.getX() && this->y > other.getY()) {
        return "thgiR";
    }
    if (this->x == other.getX() && this->y < other.getY()) {
        return "tfeL";
    }
    if (this->x > other.getX() && this->y == other.getY()) {
        return "nwoD";
    }
    if (this->x < other.getX() && this->y == other.getY()) {
        return "pU";
    }
}
