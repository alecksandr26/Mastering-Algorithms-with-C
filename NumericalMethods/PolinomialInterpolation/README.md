# Polinomial Interpolation
A method of approximating values of a function for which values are known at only a few points. Fundamental to this method is the construction of an interpolating polynomial pn(z) of degree ≤ n, where n + 1 is the number of points for which values are known.

There are many problems that can be described in terms of a function. However, often this function is not known, and we must infer what we can about it from only a small number of points. To do this, we interpolate between the points. For example, in Figure 13-1, the known points along f (x) are x0, . . ., x8, shown by circular black dots. Interpolation helps us get a good idea of the value of the function at points z0, z1, and z2, shown by white squares. This section presents polynomial interpolation.

Once we have determined the coefficients of the interpolating polynomial pn(z), we evaluate the polynomial once for each point at which we would like to know the value of f. For example, say we know the values of f at four points: x0 = –3.0, f (x0) = –5.0; x1 = –2.0, f (x1) = –1.1; x2 = 2.0, f (x2) = 1.9; and x3 = 3.0, f (x3) = 4.8; and we would like to know the value of f at z0 = –2.5, z1 = 0.0, z2 = 1.0, and z3 = 2.5. Since we know four points along f, the interpolating polynomial will have a degree of 3. Figure 13-3 is the divided-difference table for determining the coefficients of p3(z).

### Some videos
[Newton Interpolation and Divided Differences](https://www.youtube.com/watch?v=S7QIU0i1qLE)
[Newton polynonomial](https://en.wikipedia.org/wiki/Newton_polynomial)
[Divided differences](https://en.wikipedia.org/wiki/Divided_differences)
