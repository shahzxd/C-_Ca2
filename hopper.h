#ifndef HOPPER_H
#define HOPPER_H

#include "Bug.h"
#include <string>
#include <iostream>

class Hopper : public Bug {
private:
    int hopLength;

public:
    Hopper(const std::string& type, int id, int x, int y, Direction direction, int size, int hopLength)
            : Bug(type, id, x, y, direction, size), hopLength(hopLength) {}

    void move() override {
        auto newPos = calculateNewPosition(hopLength);
        position = newPos.first;
        while (newPos.second != 0) {
            direction = Direction((direction + 1 + (rand() % 3)) % 4);
            newPos = calculateNewPosition(newPos.second);
            position = newPos.first;
        }
    }

    int getHopLength() const {
        return hopLength;
    }

    std::string getOutputString() const override {
        return Bug::getOutputString() + " " + std::to_string(hopLength);
    }
};

#endif // HOPPER_H
