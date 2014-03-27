#include "astar.h"
#include <stdio.h>
#include <stdlib.h>
#include <boost/range/algorithm.hpp>
#include <set>
#include <stack>
#include <queue>

Astar::Astar(Space * problem):Algorithm(problem), path(1)
{
   target = (Astar::node *)malloc(sizeof(Astar::node));
   target->previousNode = nullptr;
   target->cost = 0;
   target->currentPoint = problem->get_end();

   head = (Astar::node *)malloc(sizeof(Astar::node));
   head->currentPoint = problem->get_start();
   head->previousNode = nullptr;
   head->nextNodes;
   head->cost = 0;
}

Astar::~Astar(){
 //todo
}

bool Astar::node::operator == (const Astar::node & other){
    bool equality = true;
    for(int x = 0; x < this->currentPoint->get_dimemsion(); x++){
        equality = equality && (this->currentPoint->get_coordinate(x) == this->currentPoint->get_coordinate(x));
    }
    return equality;
}

bool operator <(const Astar::node & rhs, const Astar::node & lhs){
    return (rhs.cost < lhs.cost);
}

bool comp(const Astar::node & rhs, const Astar::node & lhs){
    return !(rhs < lhs);
}

void Astar::run(){
 std::vector<Astar::node> openList;
 std::set<Astar::node> closedList;
 bool found = false;
 openList.push_back(*head);
 Astar::node temp;
 while( openList.size() > 0 ){//while openlist is not empty
    //temp = removeItemWithLowestCost(OpenList)
    //std::sort(openList.front(), openList.back(), comp);
    boost::sort(openList);
    temp = openList.back();
    openList.pop_back();

    //find goal condition
    if(temp == *target){
        target->previousNode = temp.previousNode;
        target->cost = temp.cost;
        found = true;
        break;
    }
    //iteration:
    else{
    //if temp not in closedList, add it
    if(closedList.count(temp) == 0){
        closedList.insert(temp);
    }
    //for each neighbor of temp
   std::vector<Astar::node> neighbors = getNeighbors(temp);
   for(auto & neighbor : neighbors){
        //add as child of temp
        temp.nextNodes.push_back(neighbor);
        //add to openlist
        openList.push_back(neighbor);
        }
    }
 }
if(found){
    //Goes up the tree from the target until it finds the starting position.
    Astar::node * temp = target;
    while (temp != nullptr) {
        path.push_back(*temp->currentPoint);
        temp = temp->previousNode;
    }
}
else{
    std::cout<< "No Path was Found" << std::endl;
}
}
void Astar::pause(){
//to be implemented with threading
}

void Astar::stop(){
//to be implemented with threading
}

void Astar::runUntil(){
//not relevant to this particular algorithm
}

Path Astar::pathGenerated(){
    Path returns(path);
    return returns;
}

Path * Astar::areaExplored(){
//todo
}

int Astar::heuristic(Astar::node const& currentLoc){
    return all_points->distance(currentLoc.currentPoint, target->currentPoint);
}

std::vector<Astar::node> Astar::getNeighbors(Astar::node & current){
    std::vector<Point *> points = all_points->getNeighbors(current.currentPoint);
    std::vector<Astar::node> neighboringNodes(points.size());
    for(int x = 0; x < points.size(); x++){
        if(points[x]->valid()){
        neighboringNodes[x].currentPoint = points[x];
        neighboringNodes[x].previousNode = &current;
        neighboringNodes[x].cost = heuristic(neighboringNodes[x]);
        }
    }
    return neighboringNodes;
}
