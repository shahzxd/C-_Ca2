#include "Bug.h"

#include <string>
//#include <list>
#include <utility>
#include <iostream>

using namespace std;

Bug::Bug(int id, pair<int, int> position, int direction, int size, bool alive, list<pair<int, int>> path) {
    this->id = id;
    this->position = position;
    this->direction = direction;
    this->size = size;   //1 - 20
    this->alive = alive;
    this->path = path;
}

bool Bug::isWayBlocked() {
    int boardWidth = 10;
    int boardHeight = 10;

    switch(direction) {
        case 1:
            if (position.second <= 0) {
                return true;
            }
            break;
        case 2:
            if (position.first >= boardWidth) {
                return true;
            }
            break;
        case 3:
            if (position.second >= boardHeight) {
                return true;
            }
            break;
        case 4:
            if (position.first <= 0) {
                return true;
            }
            break;
        default:
            break;
    }

    return false;
}
bool Bug::isIdSame(int id) {
    if (this->id == id) {
        return true;
    }
    else {
        return false;
    }
}
string Bug::bugHistory() {
    string final = to_string(id) + " " + type + " Path: ";;
    for (list<pair<int, int>>::const_iterator it = path.cbegin(); it != path.cend(); ++it) {
        final += "(" + to_string(it->first) + ", " + to_string(it->second) + "), ";
    }

    string status = "Alive!";
    if (!alive) {
        status = "Dead!";
    }

    final += status + "\n";

    return final;
}

void Bug::outputBugHistory() {
    cout << bugHistory();
}
