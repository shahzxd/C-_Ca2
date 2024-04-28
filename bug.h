#ifndef BUG_H
#define BUG_H

#include <string>
#include <utility>
#include <list>

class Bug {
protected:
    int id;
    std::pair<int, int> position;
    int direction;
    int size;
    bool alive;
    std::list<std::pair<int, int>> path;
    std::string type;

public:
    Bug(int id = 0, std::pair<int, int> position = {0, 0}, int direction = 1, int size = 1, bool alive = true, std::list<std::pair<int, int>> path = {});
    virtual ~Bug() = default;
    virtual void move() = 0;
    bool isWayBlocked() const;
    virtual void outputBug() const = 0;
    bool isIdSame(int otherId) const;
    std::string bugHistory() const;
    void outputBugHistory() const;

    void outputBugHistory();
};

#endif
