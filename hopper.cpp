#include "Hopper.h"
#include <iostream>
#include <cstdlib> // For rand()

Hopper::Hopper(int id, const std::pair<int, int>& position, int direction, int size, bool alive, const std::list<std::pair<int, int>>& path, int hopLength)
        : Bug(id, position, direction, size, alive, path), hopLength(hopLength) {
    type = "Hopper";
}

void Hopper::move() {
    if (isWayBlocked()) {
        direction = (rand() % 4) + 1; // Randomize direction if blocked
    }

    for (int i = 0; i < hopLength; ++i) {
        if (isWayBlocked()) {
            break; // Break loop if way is blocked
        } else {
            switch (direction) {
                case 1: // North
                    --position.second;
                    break;
                case 2: // East
                    ++position.first;
                    break;
                case 3: // South
                    ++position.second;
                    break;
                case 4: // West
                    --position.first;
                    break;
                default:
                    break;
            }
            path.emplace_back(position);
        }
    }
}

void Hopper::outputBug() const {
    std::string status = alive ? "Alive" : "Dead";
    std::cout << "ID: " << id << ", Type: " << type << ", Position: (" << position.first << ", " << position.second
              << "), Size: " << size << ", Direction: " << direction << ", Hop Length: " << hopLength << ", Status: " << status << std::endl;
}
