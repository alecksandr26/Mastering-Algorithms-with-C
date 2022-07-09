#include <stdlib.h>
#include <string.h>

#include "interpol.h"


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
int interpol (const double *x, const double *fx, int n, double *z, double *pz, int m)
{
    double term, *table, *coeff;
    int i, j, k;

    /* Set the array in zero */
    memset(pz, 0.0, sizeof(double) * m);
    
    /* Allocate storage for the divided difference table and coefficients */
    if ((table = (double *) malloc(sizeof(double) * n)) == NULL)
        return -1;
    
    if ((coeff = (double *) malloc(sizeof(double) * n)) == NULL) {
        free(table);
        return -1;
    }

    /* Put the coefficients inside of the table */
    memcpy(table, fx, sizeof(double) * n);

    /* Determine the coefficients of the interpolating polynomial */
    coeff[0] = table[0];

    for (k = 1; k < n; k++) {
        for (i = 0; i < n - k; i++) {
            j = i + k;
            table[i] = (table[i + 1] - table[i]) / (x[j] - x[i]);
        }

        coeff[k] = table[0];
    }

    free(table);

    
    /* Evaluate the interpolating polynomial at the specified points of 'z' */
    for (k = 0; k < m; k++) {
        pz[k] = coeff[0];

        for (j = 1; j < n; j++) {
            term = coeff[j];
            
            for (i = 0; i < j; i++)
                term = term * (z[k] - x[i]);

            pz[k] = pz[k] + term;
        }
    }

    free(coeff);

    return 0;
}






