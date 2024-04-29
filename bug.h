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
    // Constructors
    Bug(int id = 0, const std::pair<int, int>& position = {0, 0}, int direction = 1, int size = 1, bool alive = true, const std::list<std::pair<int, int>>& path = {});

    // Destructor
    virtual ~Bug() = default;

    // Pure virtual function for movement
    virtual void move() = 0;

    // Utility functions
    bool isWayBlocked() const;
    bool isIdSame(int otherId) const;
    std::string bugHistory() const;

    // Virtual function for outputting bug information
    virtual void outputBug() const = 0;
    void outputBugHistory() const;
};

#endif // BUG_H
