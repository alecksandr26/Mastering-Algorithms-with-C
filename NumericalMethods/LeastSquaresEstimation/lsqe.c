#include <math.h>
#include "lsqe.h"


/* lsqe: Return none.
   description: Uses least-squares estimation to obtain b1 and b0 in y (x) = b1x +
   b0 so that y (x) is a best-fit line through a set of points. The x-coordinates of the
   points are specified in x. The y-coordinates are specified in y. The number of
   points is specified in n. The operation returns the appropriate values in b1 and b0.
   complexity: O(n) where n is the number of points used in determining b1 and b0.
 */
void lsqe(const double *x, const double *y, int n, double *b1, double *b0)
{
    double sumx, sumy, sumx2, sumxy;
    int i;

    sumx = 0.0;
    sumy = 0.0;
    sumx2 = 0.0;        /* x^2 */
    sumxy = 0.0;        /* x * y */

    /* Computed the summation */
    for (i = 0; i < n; i++) {
        sumx += x[i];
        sumy += y[i];
        sumx2 += pow(x[i], 2.0);
        sumxy += (x[i] * y[i]);
    }

    
    /* compute the least-squares estimators */
    *b1 = (sumxy - ((sumx * sumy) / (double) n)) / (sumx2 - (pow(sumx, 2.0) / (double) n));
    *b0 = (sumy - ((*b1) * sumx)) / (double) n;
}



