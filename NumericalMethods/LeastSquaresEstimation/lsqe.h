#ifndef __LSQE_H__
#define __LSQE_H__

/* lsqe: Return none.
   description: Uses least-squares estimation to obtain b1 and b0 in y (x) = b1x +
   b0 so that y (x) is a best-fit line through a set of points. The x-coordinates of the
   points are specified in x. The y-coordinates are specified in y. The number of
   points is specified in n. The operation returns the appropriate values in b1 and b0.
   complexity: O(n) where n is the number of points used in determining b1 and b0.
 */
void lsqe(const double *x, const double *y, int n, double *b1, double *b0);

#endif
