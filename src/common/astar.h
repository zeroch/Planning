#ifndef ASTAR_H
#define ASTAR_H
#include "algorithm.h"
#include "vector"

class Astar : public Algorithm
{
public:
    Astar(Space * problem);
    ~Astar();
    void run();
    void pause();
    void stop();
    void runUntil();
    Path pathGenerated();
    Path * areaExplored();
private:
    struct node{
        Point * currentPoint;
        node * previousNode;
        std::vector<node> nextNodes;
        int cost;
        bool operator ==(const node &);
    };
    friend bool operator < (const node &, const node &);
    std::vector<Point> path;
    node * head;
    node * target;
    int heuristic(const node & currentLoc);
    std::vector<node> getNeighbors(node &);
    friend bool comp(const node & rhs, const node & lfhs);
};
#endif // ASTAR_H
