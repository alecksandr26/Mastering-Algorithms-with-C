#include <stdio.h>
#include "interpol.h"

#define x_len 4
#define z_len 3

int main()
{
    int i;
    double pz[z_len];
    const double x[] = {1.0, 2.0, 3.0, 4.0};
    const double fx[] = {2.0, 5.0, 10.0, 17.0};
    double z[] = {1.5, 2.5, 3.5};

    /* Interpol  */
    interpol(x, fx, x_len, z, pz, z_len);

    for (i = 0; i < z_len; ++i)
        printf("%f\n", pz[i]);

    
    
    return 0;
}





