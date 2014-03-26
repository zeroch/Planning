

#include <iostream>
#include <array>
#include "../common/space2d.h"
#include "../common/point2d.h"
#include "../common/space.h"
int main(int argc, char  *argv[])
{
    int  start_arr [] = {120,75};
    Point2D start_point(start_arr, false, 1);
    int  end_arr [] = {180,75};
    Point2D end_point(end_arr, false, 2);

    Point2D temp = start_point;

    std::cout << "hello world!" << std::endl;
    std::cout << "this point is "<< temp.get_coordinate(0) << std::endl;
    Space  * my_space = new Space2D();    

    // test to read pgm
    char *filename="../pic/circular_map.pgm";
    my_space->initFromImage(filename);
    
    //my_space->printSpace();
	/* code */
    return 0;
}
