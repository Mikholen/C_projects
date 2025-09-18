#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "preambule.h"

void swap_values_in_array (void *array, size_t arr_elem_size, int i, int j) {
    
    // unsigned char *arr = (pointer_and_length *)array;
    // unsigned char *a = arr + i * arr_elem_size;
    // unsigned char *b = arr + j * arr_elem_size;

    // for (size_t k = 0; k < arr_elem_size; k++) {

    pointer_and_length tmp = ((pointer_and_length *)array)[i];
    ((pointer_and_length *)array)[i] = ((pointer_and_length *)array)[j];
    ((pointer_and_length *)array)[j] = tmp; 
    // }
}

int need_to_swap_for_classic_alphabet_order (const void *elem_1, const void *elem_2) {

    const pointer_and_length *element_1 = (const pointer_and_length *)elem_1;
    const pointer_and_length *element_2 = (const pointer_and_length *)elem_2;

    for (int t_1 = 0, t_2 = 0; (t_1 < (*element_1).line_length) && 
                               (t_2 < (*element_2).line_length); t_1++, t_2++) {

        if (!isalpha ((*element_1).line_pointer[t_1])) {

            t_1++;
        }

        if (!isalpha ((*element_2).line_pointer[t_2])) {

            t_2++;
        }

        if (tolower (*((*element_1).line_pointer + t_1)) - 
            tolower (*((*element_2).line_pointer + t_2)) > 0) {

            return 1; 
        }

        else if (tolower (*((*element_1).line_pointer + t_1)) - 
                 tolower (*((*element_2).line_pointer + t_2)) < 0) {

            return -1;
        }
    }

    return 0;
}

int need_to_swap_for_reverse_alphabet_order (const void *elem_1, const void *elem_2) {

    const pointer_and_length *element_1 = (const pointer_and_length *)elem_1;
    const pointer_and_length *element_2 = (const pointer_and_length *)elem_2;
    
    if ((*element_2).line_length == 2) {

        return 1;
    }

    for (int t_1 = 1, t_2 = 1; (t_1 <= (*element_1).line_length) && 
                               (t_2 <= (*element_2).line_length); t_1++, t_2++) {

        if (!isalpha ((*element_1).line_pointer[(*element_1).line_length - t_1])) {

            t_1++;
        }

        if (!isalpha ((*element_2).line_pointer[(*element_2).line_length - t_2])) {

            t_2++;
        }

        if (tolower (*((*element_1).line_pointer + (*element_1).line_length - t_1)) - 
            tolower (*((*element_2).line_pointer + (*element_2).line_length - t_2)) > 0) {

            return 1; 
        }

        else if (tolower (*((*element_1).line_pointer + (*element_1).line_length - t_1)) - 
                 tolower (*((*element_2).line_pointer + (*element_2).line_length - t_2)) < 0) {

            return -1;
        }
    }

    return -1;
}

void bubble_sort (void *pointers_array, int num_lines, size_t arr_elem_size, int (*need_to_swap) (const void *, const void *), void (*swap_values_in_array) (void *, size_t, int, int)) {

    for (int ind_1 = 0; ind_1 + 1 < num_lines; ind_1++) {

        for (int ind_2 = 0; ind_2 + 1 < num_lines - ind_1; ind_2++) {

            if (need_to_swap ((char *)pointers_array + ind_2 * arr_elem_size, (char *)pointers_array + (ind_2 + 1) * arr_elem_size) >= 0) {

                swap_values_in_array (pointers_array, arr_elem_size, ind_2, ind_2 + 1);
            }
        }
    }
}