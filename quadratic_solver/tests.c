#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "preambule.h"

//                                                         a     b      c      case  x1      x2
const struct corresponding_coeffs_and_results tests[7] = {{2.0, -4.12, -6.23,  2,    3.074, -1.014},
                                                          {0.0,  2.0,  -3.0,   1,    1.5,    NAN},
                                                          {5.0, -25.0,  0.0,   2,    0.0,    5.0},
                                                          {2.0,  5.5,   32.0, -2,    NAN,    NAN},
                                                          {6.0,  3.0,  -24.0,  2,    1.766, -2.266},
                                                          {0.0,  .0,   0.0,   3,    NAN,    NAN},
                                                          {0.0,  0.0,   4.6,   0,    NAN,    NAN}};

bool test_provided_case (struct corresponding_coeffs_and_results test) {

    double x1 = NAN, x2 = NAN;
    int solution_case = quadratic_equation_solver (test.a, test.b, test.c, &x1, &x2);

    if (solution_case == test.solution_case){

        if (solution_case == CASE_NEGATIVE_DISCRIMINANT || solution_case == 0 || solution_case == CASE_INF_SOLUTIONS) {

            if ((isnan (x1) && isnan (test.x1)) && (isnan (x2) && isnan (test.x2)))
                return true;
        }

        else if (solution_case == 1) {
            if (((isnan (x1) && isnan(test.x1)) && compare_with_PRECISION (test.x2, x2)) ||
                ((isnan (x1) && isnan(test.x2)) && compare_with_PRECISION (test.x2, x1)) ||
                ((isnan (x2) && isnan(test.x1)) && compare_with_PRECISION (test.x1, x2)) ||
                ((isnan (x2) && isnan(test.x2)) && compare_with_PRECISION (test.x1, x1)))
                return true;
        }
        
        else if ((compare_with_PRECISION (test.x1, x1) && compare_with_PRECISION (test.x2, x2)) ||
                 (compare_with_PRECISION (test.x1, x2) && compare_with_PRECISION (test.x2, x1)))
            return true;
    }
    printf ("\nTEST FAILED\n\na : %f, b : %f, c : %f\nRIGHT SOLUTION :\n CASE %d, x1 : %f, x2 : %f\n\n", 
                                test.a, test.b, test.c, test.solution_case, test.x1, test.x2);
    printf ("OBTAINED SOLUTION :\n CASE %d, x1 : %f, x2 : %f\n\n\n", solution_case, x1, x2);
    
    return false;
}

bool tests_check () {

    int flag = 0;
    for (int i = 0; i < sizeof(tests) / sizeof(tests[0]); i++) {
        if (test_provided_case (tests[i]))
            flag++;
    }
    
    if (flag == sizeof(tests) / sizeof(tests[0])) {
        printf ("\nALL TESTS WERE PASSED CORRECTLY\n--------------------------------\n\n\n");
        return true;
    }

    return false;
}