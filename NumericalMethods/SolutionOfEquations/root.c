#include "root.h"
#include <math.h>



/* root:
   Return: Value 0 if a root is found, –1 otherwise
   Description Computes the root of f to which Newton’s method converges
   given an initial iteration point. This point is specified in x[0]. The derivative of f
   is specified in g. The argument n is the maximum number of iterations to per-
   form. The argument delta is the difference between successive approximations at
   which to stop iterating. Upon return, successive values of x calculated during the
   iteration process are returned in the x array. Upon return, n contains the number
   of values in array x. It is the responsibility of the caller to manage the storage
   associated with x.
   Complexity: O(n), where n is the maximum number of iterations the caller wishes to perform
 */
int root(double (*f)(double x), double (*g)(double x), double *x, int *n, double delta)
{
    int satisfied, i;


    i = 0;
    satisfied = 0;
    /* Do the iterations to find the root of f */
    while (!satisfied  && i + 1 < *n) {
        /* Determine the next iteration */
        x[i + 1] = x[i] - (f(x[i]) / g(x[i]));
        
        /* Determine  wheter the desired approximations has been obtained */
        if (fabs(x[i + 1] - x[i]) < delta)
            satisfied = 1;
        i++;
    }

    if (i == 0)
        *n = 1;
    else
        *n = i + 1;

    return (satisfied) ? 0 : -1;
}











