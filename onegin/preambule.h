#include <stdbool.h>

struct pointer_and_length {

    char *line_pointer;
    int line_length;
};

typedef struct pointer_and_length pointer_and_length;

void print_initial_text (char *text);
void print_line_tioma_asked_for_long_function_title_so_here_it_is_enjoy (pointer_and_length value, char letter);
size_t get_text_size (const char *filename);
void read_text (char *text, const char *filename, size_t text_size);
int count_lines (char *text, size_t text_size);
pointer_and_length *create_pointers_array (char *text, size_t text_size, int num_lines);
void swap_values_in_array (pointer_and_length *array, int i, int j);
void bubble_sort (pointer_and_length *pointers_array, int num_lines, bool (*need_to_swap) (int, int, pointer_and_length *));
void print_sorted_text (pointer_and_length *pointers_array, int num_lines);
bool need_to_swap_for_classic_alphabet_order (int ind_1, int ind_2, pointer_and_length *pointers_array);
bool need_to_swap_for_reverse_alphabet_order (int ind_1, int ind_2, pointer_and_length *pointers_array);