#include <stdio.h>
#include <stdlib.h>
#include "preambule.h"

int main () {

    const char *filename = "text.txt";
    size_t text_size = get_text_size (filename) + 3;
    
    char *initial_text = (char *)calloc (text_size, sizeof (char));

    read_text (initial_text, filename, text_size);

    int num_lines = count_lines (initial_text, text_size);

    pointer_and_length *lines_pointers_and_len = create_pointers_array (initial_text, text_size, num_lines);

    // qsort (lines_pointers_and_len, num_lines, sizeof (lines_pointers_and_len[0]), need_to_swap_for_reverse_alphabet_order);
    bubble_sort (lines_pointers_and_len, num_lines, sizeof (lines_pointers_and_len[0]), need_to_swap_for_reverse_alphabet_order, swap_values_in_array);
    print_sorted_text (lines_pointers_and_len, num_lines);

    print_initial_text (initial_text);

    free (initial_text);
    free (lines_pointers_and_len);

    return 0;
}