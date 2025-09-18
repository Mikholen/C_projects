struct pointer_and_length {

    char *line_pointer;
    int line_length;
};

typedef struct pointer_and_length pointer_and_length;

void print_initial_text (char *text);
void print_line (pointer_and_length value, char letter);
size_t get_text_size (const char *filename);
void read_text (char *text, const char *filename, size_t text_size);
int count_lines (char *text, size_t text_size);
pointer_and_length *create_pointers_array (char *text, size_t text_size, int num_lines);
void swap_values_in_array (void *array, size_t arr_elem_size, int i, int j);
void bubble_sort (void *pointers_array, int num_lines, size_t arr_elem_size, int (*need_to_swap) (const void *, const void *), void (*swap_values_in_array) (void *, size_t, int, int));
void print_sorted_text (pointer_and_length *pointers_array, int num_lines);
int need_to_swap_for_classic_alphabet_order (const void *elem_1, const void *elem_2);
int need_to_swap_for_reverse_alphabet_order (const void *elem_1, const void *elem_2);