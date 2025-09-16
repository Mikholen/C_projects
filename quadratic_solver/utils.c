#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "preambule.h"

bool compare_with_PRECISION (double num_1, double num_2) {

    int comp_1 = (int) round (num_1 * pow (10, FORMAT_LEN)), 
        comp_2 = (int) round (num_2 * pow (10, FORMAT_LEN));
    if (comp_1 == comp_2)
        return true;
    return false;
}

bool compare_to_zero (double number) {
    if (number < PRECISION && number > -PRECISION)
        return true;
    else 
        return false;
}