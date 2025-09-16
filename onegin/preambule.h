struct pointer_and_length {

    char *line_pointer;
    int line_length;
};

void print_initial_text (char *text);
void print_line_tioma_asked_for_long_function_title_so_here_it_is_enjoy (struct pointer_and_length value, char letter);
size_t get_text_size (const char *filename);
void read_text (char *text, const char *filename, size_t text_size);
int count_lines (char *text, size_t text_size);
struct pointer_and_length *create_pointers_array (char *text, size_t text_size, int num_lines);
void swap_values_in_array (struct pointer_and_length *array, int i, int j);
void bubble_sort (struct pointer_and_length *pointers_array, int num_lines, bool (*need_to_swap) (int, int, struct pointer_and_length *));
void print_sorted_text (struct pointer_and_length *pointers_array, int num_lines);
bool need_to_swap_for_classic_alphabet_order (int ind_1, int ind_2, struct pointer_and_length *pointers_array);
bool need_to_swap_for_reverse_alphabet_order (int ind_1, int ind_2, struct pointer_and_length *pointers_array);