#include <queue>
#include "point.h"

class Path
{
public:
	Path();
    Path(std::vector<Point>);
	~Path();
    void append(Point *);
    Point getNext();
    void trimPath();
	/* data */
private:
	Point * start;
	Point * end;
    std::queue<Point> path;
	
};
