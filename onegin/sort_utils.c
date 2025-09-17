#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>
#include "preambule.h"

void swap_values_in_array (pointer_and_length *array, int i, int j) {
    
    pointer_and_length tmp = array[j];
    array[j] = array[i];
    array[i] = tmp;
}

bool need_to_swap_for_classic_alphabet_order (int ind_1, int ind_2, pointer_and_length *pointers_array) {

    for (int t_1 = 0, t_2 = 0; (t_1 < pointers_array[ind_1].line_length) && 
                               (t_2 < pointers_array[ind_2].line_length); t_1++, t_2++) {

        if (!isalpha (pointers_array[ind_1].line_pointer[t_1])) {

            t_1++;
        }

        if (!isalpha (pointers_array[ind_2].line_pointer[t_2])) {

            t_2++;
        }

        if (tolower (*(pointers_array[ind_1].line_pointer + t_1)) - 
            tolower (*(pointers_array[ind_2].line_pointer + t_2)) > 0) {

            return true; 
        }

        else if (tolower (*(pointers_array[ind_1].line_pointer + t_1)) - 
                 tolower (*(pointers_array[ind_2].line_pointer + t_2)) < 0) {

            return false;
        }
    }

    return false;
}

bool need_to_swap_for_reverse_alphabet_order (int ind_1, int ind_2, pointer_and_length *pointers_array) {

    if (pointers_array[ind_2].line_length == 2) {

        return true;
    }

    for (int t_1 = 1, t_2 = 1; (t_1 <= pointers_array[ind_1].line_length) && 
                               (t_2 <= pointers_array[ind_2].line_length); t_1++, t_2++) {

        if (!isalpha (pointers_array[ind_1].line_pointer[pointers_array[ind_1].line_length - t_1])) {

            t_1++;
        }

        if (!isalpha (pointers_array[ind_2].line_pointer[pointers_array[ind_2].line_length - t_2])) {

            t_2++;
        }

        if (tolower (*(pointers_array[ind_1].line_pointer + pointers_array[ind_1].line_length - t_1)) - 
            tolower (*(pointers_array[ind_2].line_pointer + pointers_array[ind_2].line_length - t_2)) > 0) {

            return true; 
        }

        else if (tolower (*(pointers_array[ind_1].line_pointer + pointers_array[ind_1].line_length - t_1)) - 
                 tolower (*(pointers_array[ind_2].line_pointer + pointers_array[ind_2].line_length - t_2)) < 0) {

            return false;
        }
    }

    return false;
}

void bubble_sort (pointer_and_length *pointers_array, int num_lines, bool (*need_to_swap) (int, int, pointer_and_length *)) {

    for (int ind_1 = 0; ind_1 + 1 < num_lines; ind_1++) {

        for (int ind_2 = 0; ind_2 + 1 < num_lines - ind_1; ind_2++) {

            if (need_to_swap (ind_2, ind_2 + 1, pointers_array)) {

                swap_values_in_array (pointers_array, ind_2, ind_2 + 1);
            }
        }
    }
}