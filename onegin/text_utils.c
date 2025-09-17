#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "preambule.h"

void print_initial_text (char *text) {

    printf ("\nINITIAL TEXT :\n");
    printf ("%s", text);
}

void print_sorted_text (pointer_and_length *pointers_array, int num_lines) {

    for (int i = 0; i < num_lines; i++) {

        for (int t = 0; t < pointers_array[i].line_length; t++) {
            printf ("%c", *(pointers_array[i].line_pointer + t));
        }
    }
}

void print_line_tioma_asked_for_long_function_title_so_here_it_is_enjoy (pointer_and_length value, char letter) {

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

pointer_and_length *create_pointers_array (char *text, size_t text_size, int num_lines) {

    pointer_and_length *pointers_array = (pointer_and_length *)calloc ((size_t)num_lines, sizeof (pointer_and_length));

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