#ifndef PREAMBULE_H
#define PREAMBULE_H 

struct corresponding_coeffs_and_results {
    double a;
    double b;
    double c;
    int solution_case;
    double x1;
    double x2;
};

extern const int FORMAT_LEN;
extern const double PRECISION;
extern const int CASE_INF_SOLUTIONS;
extern const int CASE_NEGATIVE_DISCRIMINANT;
extern const struct corresponding_coeffs_and_results tests[7];

int get_coefficients (double *a, double *b, double *c);
int quadratic_equation_solver (double a, double b, double c, double *x1, double *x2);
void solver_output (int solution_case, double x1, double x2);
bool compare_to_zero (double number);
bool compare_with_PRECISION (double num_1, double num_2);
bool test_provided_case (struct corresponding_coeffs_and_results test);
bool tests_check ();

#endif