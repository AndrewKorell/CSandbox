
#ifndef __node__
    #define __node__
#endif 

typedef struct {
    int number;
    int noOfNeighbors;
    int *neighbors;
    int order;
}node;
