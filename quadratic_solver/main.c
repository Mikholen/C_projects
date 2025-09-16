#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <stdbool.h>
#include "preambule.h"

int main () {

    double a = NAN, b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;

    if (!tests_check ())
        return 0;

    if (get_coefficients (&a, &b, &c) != 3)
        return 0;

    int solution_case = quadratic_equation_solver (a, b, c, &x1, &x2);

    solver_output (solution_case, x1, x2);

    return 0;
}