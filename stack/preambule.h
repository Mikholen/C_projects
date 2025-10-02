#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

typedef struct Stack_info {

    size_t n_elements;
    size_t max_size;
    size_t data_len;
    int *data;
    size_t hash_sizes;
    int hash_arr;
} Stack_info;

extern const int KANAREIKA;
extern const int N_KANAREEK;
extern const size_t INITIAL_SIZE;

void create_stack (Stack_info *stack, const size_t max_size);
size_t hash_func_sizes (const Stack_info *stack);
int hash_func_arr (const Stack_info *stack);
void push_back (Stack_info *stack, const int element);
int pop (Stack_info *stack);
void print_stack (const Stack_info *stack);
void reallocate_memory (Stack_info *stack, size_t new_len);
bool stack_check (const Stack_info *stack);