#include <math.h>
#include <assert.h>
#include <stdlib.h>
#include "part1.h"

/* Luis Olivar, lao294@nyu.edu, 02/28/2017*/

// Set the x and y fields of the point structure pointed to by pt
// to the x and y values passed in as arguments.  The point structure
// is defined in the part1.h header file.
//
// This should only take a couple of lines.
void set_point(struct point* pt, double x, double y)
{
    pt->x = x;
    pt->y = y;
    //assert(0);
}

// Create and return a new point with x and y
// initialized to x and y
//
// This should only take a couple of lines.
struct point* create_point(double x, double y)
{
    struct point *ptr = malloc(sizeof(ptr));
    ptr->x = x;
    ptr->y = y;
    //assert(0);
    return ptr;
}

// Compute the planar distance between two points. Recall that the
// distance between two points in a plane is computed as follows. Label
// the two points (x1, y1) and (x2, y2).  Let dx be the difference
// between x1 and x2 and dy be the difference between y1 and y2. The
// distance between the two points is the square root of the sum of dx
// squared plus dy squared.
//
// Hint: Use the sqrt function from math.h.  You do not need to use
// the pow function; x * x is sufficient to square a variable.
double point_dist(struct point *pt1, struct point *pt2)
{
    double dy, dx, x1, x2, y1, y2;

    struct point* p1 = pt1;
    struct point* p2 = pt2;

    x1 = p1->x;
    x2 = p2->x;
    y1 = p1->y;
    y2 = p2->y;

    dx = x2 - x1;
    dy = y2 - y1;

    double dist = sqrt((dx * dx) + (dy * dy));


    //assert(0);
    return dist;
}
