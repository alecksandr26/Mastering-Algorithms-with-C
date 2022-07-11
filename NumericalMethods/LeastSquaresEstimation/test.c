#include <stdio.h>
#include "lsqe.h"

#define n 9

int main()
{
    double x[] = {-4.0, -3.0, -2.0, -1.5, -0.5, 1.0, 2.0, 3.5, 4.0};
    double y[] = {-3.0, -1.0, -2.0, -0.5, 1.0, 0.0, 1.5, 1.0, 2.5};
    double b1, b0;
    
    b1 = b0 = 0.0;
    lsqe(x, y, n, &b1, &b0);

    printf("b1 = %f | b0 = %f\n", b1, b0);
    
    return 0;
}


