#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include "preambule.h"

const int FORMAT_LEN = 3;
const double PRECISION = 1e-6;
const int CASE_INF_SOLUTIONS = 3;
const int CASE_NEGATIVE_DISCRIMINANT = -2; 

int get_coefficients (double *a, double *b, double *c) {
    
    assert (a != NULL && b != NULL && c != NULL);
    
    printf ("Enter coefficients of the quadratic equation (real numbers): \n");
    
    if (scanf ("%lf %lf %lf", a, b, c) == 3)
        return 3;
}

int quadratic_equation_solver (double a, double b, double c, double *x1, double *x2) {
    
    assert (x1 != NULL && x2 != NULL);
    assert (!isnan (a) && !isnan (b) && !isnan (c));

    if (compare_to_zero(a)) {
        if (compare_to_zero(b) && compare_to_zero(c)) {
            return CASE_INF_SOLUTIONS;
        }
        else if (compare_to_zero(b)) {
        return 0;
        }
        else {
            *x1 = -c / b;
            return 1;
        }
    }

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        double sqrt_discriminant = sqrt (discriminant);
        *x1 = (-b + sqrt_discriminant) / (2 * a);
        *x2 = (-b - sqrt_discriminant) / (2 * a);
        return 2; 
    }
    else if (discriminant < 0) {
        return CASE_NEGATIVE_DISCRIMINANT;
    }
    else
        *x1 = -b / (2*a);
    
    return 1;
}

void solver_output (int solution_case, double x1, double x2) {

    if (solution_case == CASE_NEGATIVE_DISCRIMINANT)
        printf ("No real solutions (discriminant < 0)\n");

    else if (solution_case == 0)
        printf ("No solutions\n");
    
    else if (solution_case == CASE_INF_SOLUTIONS)
        printf ("Any number is a solution");

    else if (solution_case == 1)
        printf ("Solution: %.*f", FORMAT_LEN, x1);

    else if (solution_case == 2)
        printf ("Solutions: %.*f, %.*f", FORMAT_LEN, x1, FORMAT_LEN, x2);
}