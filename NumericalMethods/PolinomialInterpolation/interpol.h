#ifndef __INTERPOL_H__
#define __INTERPOL_H__


/* interpol: 0 if interpolating is successful, or –1 otherwise
   Determines the value of a function at specified points using polynomial interpolation
   x and fx: Are the gived points of the function
   n: Is the amount of points
   z: Is the points that we want to evalueate
   pz: Is where we are going to plot the results
   m: Is the amount of z points
   complexity: O(mn2), where m is the number of values to determine and n is
   the number of points at which values are known
 */
int interpol(const double *x, const double *fx, int n, double *z, double *pz, int m);




#endif
