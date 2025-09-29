#include <stdio.h>
#include <math.h>
// #include <stdbool.h>

typedef struct Stack_info {

    size_t n_elements;
    size_t max_size;
    int *data;
    size_t data_len;
    long long int hash;
} Stack_info;

extern const int KANAREIKA;
extern const int N_KANAREEK;

void create_stack (Stack_info *stack, size_t max_size);
long long int hash_function (size_t n_elements, size_t max_size);
void push_back (Stack_info *stack, int element);
int pop (Stack_info *stack);
void print_stack (Stack_info *stack);