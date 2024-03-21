#include <stdio.h>
#include <stdlib.h>


// typedef struct {
//     void (*cb) (my_callback *cb);
// } my_callback;

void A()
{
    printf("Function A\n");
}

void B(void (*ptr)())
{
    printf("Function B\n");
    ptr(); 
}

int main()
{
    B(A);
}

