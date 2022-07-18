#  Solution of Equations
One of the most fundamental problems in scientific computing is solving equations of the form f (x) = 0. This is often referred to as finding the roots, or zeros, of f (x). Here, we are interested in the real roots of f (x), as opposed to any complex roots it might have. Specifically, we will focus on finding real roots when f (x) is a polynomial.
## Finding Roots with Newton’s Method
Although factoring and applying formulas are simple ways to determine the roots of polynomial equations, a great majority of the time polynomials are of a large enough degree and sufficiently complicated that we must turn to some method of approximation. One of the best approaches is Newton’s method. Fundamentally, Newton’s method looks for a root of f (x) by moving closer and closer to it through a series of iterations. We begin by choosing an initial value x = x0 that we think is near the root we are interested in. Then, we iterate using the formula:
![image](https://user-images.githubusercontent.com/66882463/179577133-646972d2-9ff7-45b3-a457-b6c8bb76d5f1.png)

until xi + 1 is a satisfactory approximation. In this formula, f (x) is the polynomial for which we are trying to find a root, and f'(x) is the derivative of f (x).
