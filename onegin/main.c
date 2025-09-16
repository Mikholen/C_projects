#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <sys/stat.h>

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

int main () {

    const char *filename = "text.txt";
    size_t text_size = get_text_size (filename) + 3;
    
    char *initial_text = (char *)calloc (text_size, sizeof (char));

    read_text (initial_text, filename, text_size);

    int num_lines = count_lines (initial_text, text_size);

    struct pointer_and_length *lines_pointers_and_len = create_pointers_array (initial_text, text_size, num_lines);

    bubble_sort (lines_pointers_and_len, num_lines, need_to_swap_for_reverse_alphabet_order);
    print_sorted_text (lines_pointers_and_len, num_lines);

    print_initial_text (initial_text);

    free (initial_text);
    free (lines_pointers_and_len);

    return 0;
}

void print_initial_text (char *text) {

    printf ("\nINITIAL TEXT :\n");
    printf ("%s", text);
}

size_t get_text_size (const char *filename) {

    struct stat text_stat;
    stat (filename, &text_stat);
    return (size_t)text_stat.st_size;
}

void read_text (char *text, const char *filename, size_t text_size) {

    FILE *file = fopen (filename, "r");
    fread (text, sizeof (char), text_size, file);
    fclose (file);

    for (size_t i = text_size - 1; i > 0; i--) {

        if ((text[i] == '\0') && (text[i - 1] == '\0') && (text[i - 2] != '\0')) {

            text[i - 1] = '\r';
            text[i] = '\n';
            break;
        }
    }
}

int count_lines (char *text, size_t text_size) {

    int num_lines = 0;

    for (size_t i = 0; i < text_size; i++) {
        
        if (text[i] == '\n') 
            num_lines++;
    }
    
    return num_lines;
}

struct pointer_and_length *create_pointers_array (char *text, size_t text_size, int num_lines) {

    struct pointer_and_length *pointers_array = (struct pointer_and_length *)calloc ((size_t)num_lines, sizeof (struct pointer_and_length));

    int pointer_number = 0;

    pointers_array[0].line_pointer = &text[0];
    pointer_number++;
    for (size_t i = 1; i < text_size; i++) {
        
        if ((text[i - 1] == '\n') && (text[i] != '\0')) {

            pointers_array[pointer_number].line_pointer = &text[i];
            pointers_array[pointer_number - 1].line_length = (int)(pointers_array[pointer_number].line_pointer - 
                                                                   pointers_array[pointer_number - 1].line_pointer);
            pointer_number++;
        }
    }

    for (size_t i = text_size - 1; i > 0; i--) {

        if (text[i] == '\n') {

            pointers_array[pointer_number - 1].line_length = (int)(pointers_array[0].line_pointer + i + 1 - 
                                                                   pointers_array[pointer_number - 1].line_pointer);
            break;
        }
    }

    return pointers_array;
}

void swap_values_in_array (struct pointer_and_length *array, int i, int j) {
    
    struct pointer_and_length tmp = array[j];
    array[j] = array[i];
    array[i] = tmp;
}

bool need_to_swap_for_classic_alphabet_order (int ind_1, int ind_2, struct pointer_and_length *pointers_array) {

    for (int t = 0; (t < pointers_array[ind_1].line_length) && 
                    (t < pointers_array[ind_2].line_length); t++) {

        if (tolower (*(pointers_array[ind_1].line_pointer + t)) - 
            tolower (*(pointers_array[ind_2].line_pointer + t)) > 0) {

            return true; 
        }

        else if (tolower (*(pointers_array[ind_1].line_pointer + t)) - 
                 tolower (*(pointers_array[ind_2].line_pointer + t)) < 0) {

            return false;
        }
    }

    return false;
}

bool need_to_swap_for_reverse_alphabet_order (int ind_1, int ind_2, struct pointer_and_length *pointers_array) {

    if (pointers_array[ind_2].line_length == 2) {

        return true;
    }

    for (int t = 2; (t <= pointers_array[ind_1].line_length) && 
                    (t <= pointers_array[ind_2].line_length); t++) {

        if (tolower (*(pointers_array[ind_1].line_pointer + pointers_array[ind_1].line_length - t)) - 
            tolower (*(pointers_array[ind_2].line_pointer + pointers_array[ind_2].line_length - t)) > 0) {

            return true; 
        }

        else if (tolower (*(pointers_array[ind_1].line_pointer + pointers_array[ind_1].line_length - t)) - 
                 tolower (*(pointers_array[ind_2].line_pointer + pointers_array[ind_2].line_length - t)) < 0) {

            return false;
        }
    }

    return false;
}

void bubble_sort (struct pointer_and_length *pointers_array, int num_lines, bool (*need_to_swap) (int, int, struct pointer_and_length *)) {

    for (int ind_1 = 0; ind_1 + 1 < num_lines; ind_1++) {

        for (int ind_2 = 0; ind_2 + 1 < num_lines - ind_1; ind_2++) {

            if (need_to_swap (ind_2, ind_2 + 1, pointers_array)) {

                swap_values_in_array (pointers_array, ind_2, ind_2 + 1);
            }
        }
    }
}

void print_sorted_text (struct pointer_and_length *pointers_array, int num_lines) {

    for (int i = 0; i < num_lines; i++) {

        for (int t = 0; t < pointers_array[i].line_length; t++) {
            printf ("%c", *(pointers_array[i].line_pointer + t));
        }
    }
}

void print_line_tioma_asked_for_long_function_title_so_here_it_is_enjoy (struct pointer_and_length value, char letter) {

    printf ("->");

    for (int i = 0; i < value.line_length; i++) {

        if (letter == 'd') {

            printf ("%d ", value.line_pointer[i]);
        }

        else {

            printf ("%c", value.line_pointer[i]);
        }
    }
    printf ("\n");
}