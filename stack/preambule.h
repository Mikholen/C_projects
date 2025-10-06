#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include <stddef.h>
#include <stdbool.h>

typedef int elem_type;

typedef enum {

    INVALID_POINTER_FOR_STACK = 1,
    BEGIN_KANAREIKA_NOT_FOUND = 2,
    END_KANAREIKA_NOT_FOUND = 4,
    HASH_STRUCT_STACK_MISMATCH = 8,
    HASH_DATA_ARRAY_MISMATCH = 16
} error_type;

typedef struct Stack_info {

    size_t n_elements;
    size_t max_size;
    size_t data_len;
    elem_type *data;
    size_t hash_sizes;
    elem_type hash_arr;
} Stack_info;

extern const elem_type KANAREIKA;
extern const int N_KANAREEK;
extern const size_t INITIAL_SIZE;

void create_stack (Stack_info *stack, const size_t max_size);
size_t hash_func_stack (const Stack_info *stack);
elem_type hash_func_arr (const Stack_info *stack);
bool push_back (Stack_info *stack, const elem_type element);
elem_type pop (Stack_info *stack);
void print_stack (const Stack_info *stack);
bool stack_check (const Stack_info *stack);
void dump (unsigned char flag);
void destructor (Stack_info *stack);