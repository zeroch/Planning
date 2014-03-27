#include "path.h"

 Path::Path():path(){

 }

 Path::Path(std::vector<Point> rawPath):path(){
     for(int x = 0; x < rawPath.size(); x++){
         path.push(rawPath.back());
         rawPath.pop_back();
     }
 }

 Point Path::getNext(){
    Point returns = path.front();
    path.pop();
    return returns;
 }

 void Path::trimPath(){
//todo
 }
