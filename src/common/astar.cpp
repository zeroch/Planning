#include "astar.h"
#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <queue>

Astar::Astar(Space * problem):Algorithm(problem)
{
   target = problem->get_end();
   tail = NULL;
   head = (Astar::node *)malloc(sizeof(Astar::node));
   head->currentPoint = problem->get_start();
   head->previousNode = nullptr;
   head->nextNodes = *((std::vector<Astar::node *> *)
                       malloc(sizeof(std::vector<Astar::node *>)));
}

Astar::~Astar(){
  std::stack<Astar::node *> nodeStack;
  bool treeHasNodes = true;
  nodeStack.push(head);
  while(!nodeStack.empty()){
    node * currentNode = nodeStack.top();
    nodeStack.pop();
    for(std::vector<Astar::node*>::iterator it = currentNode->nextNodes.begin();
        it != currentNode->nextNodes.end() ; it++){
        nodeStack.push(*it);
     }
    free((void*)currentNode);
   }
}

void Astar::run(){
    std::queue<Astar::node *> tmp;
    tmp.push(head);
    while(tmp.size()>0){
        Astar::node * current  = tmp.front();
        tmp.pop();
        std::vector<Point *> children = all_points->getNeighbors(current->currentPoint);
        for(int x = 0; x<children.size(); x++){

        }
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

Path * Astar::pathGenerated(){

}

Path * Astar::areaExplored(){

}

int Astar::heuristic(Point *currentLoc){
    return all_points->distance(currentLoc, target);
}
