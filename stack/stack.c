#include "preambule.h"

static void reallocate_memory (Stack_info *stack, const size_t new_len);

const elem_type KANAREIKA = 9327645;
const int N_KANAREEK = 2;
const size_t INITIAL_SIZE = 48;

void create_stack (Stack_info *stack, const size_t max_size) {

    if (max_size <= 0) {

        printf ("Unable to create stack with maximum size <= 0 *-*\n");
    }

    else if (stack == NULL) {

        printf ("Invalid input *-*\n");
    }
    
    else if (stack->data != NULL) {

        printf ("Stack is already initialized *-*\n");
    }

    else { 

        stack->n_elements = (size_t )0;
        stack->max_size = max_size;
        stack->data = (elem_type *)calloc (N_KANAREEK, sizeof(elem_type));
        stack->data[0] = stack->data[1] = KANAREIKA;
        stack->data_len = N_KANAREEK;

        stack->hash_sizes = hash_func_stack (stack);
        stack->hash_arr = hash_func_arr (stack);
    }
}

size_t hash_func_stack (const Stack_info *stack) {

    return (stack->n_elements + stack->max_size + stack->data_len + (size_t)stack->data);
}

elem_type hash_func_arr (const Stack_info *stack) {

    elem_type return_val = 0;

    for (size_t i = 1; i < stack->n_elements; i++) {

        return_val += stack->data[i] % 78;
    }

    return return_val;
}

bool push_back (Stack_info *stack, const elem_type element) {

    // if (!stack_check (stack)) {

    //     printf ("Stack has been spoiled *-*\n");

    //     return false;
    // }

    if (stack_check (stack)) {

        if ((stack->n_elements + 1) > stack->max_size) {

            printf ("Stack overfull can not push element *-*\n");

            return false;
        }

        if ((stack->n_elements + 1 + N_KANAREEK) > stack->data_len) {

            reallocate_memory (stack, (stack->n_elements + N_KANAREEK) * 2);
        }
        
        (stack->data)[stack->n_elements + N_KANAREEK - 1] = element;
        (stack->data)[stack->n_elements + N_KANAREEK] = KANAREIKA;
        stack->n_elements++;

        stack->hash_arr = hash_func_arr (stack);
        stack->hash_sizes = hash_func_stack (stack);

        return true;
    }
    return false;
}

elem_type pop (Stack_info *stack) {

    // if (!stack_check (stack)) {

    //     printf ("Stack has been spoiled *-*\n");
    // }

    if (stack_check (stack)) {

        if (stack->n_elements == 0) {

            printf ("Stack is empty nothing to pop *-*\n");
            return 0;
        }

        reallocate_memory (stack, stack->n_elements + N_KANAREEK - 1);

        elem_type value = stack->data[stack->n_elements];        
        stack->data[stack->n_elements] = KANAREIKA;
        stack->n_elements--;

        stack->hash_sizes = hash_func_stack (stack);
        stack->hash_arr = hash_func_arr (stack);

        return value;
    }

    return 0;
}

void print_stack (const Stack_info *stack) {

    for (size_t i = 0; i < stack->n_elements + N_KANAREEK; i++) {

        printf ("%d ", stack->data[i]);
    }

    printf ("\n");
}

static void reallocate_memory (Stack_info *stack, const size_t new_len) {

    stack->data_len = new_len;
    stack->data = (elem_type *)realloc (stack->data, new_len);
}

void destructor (Stack_info *stack) {

    free (stack->data);
}

bool stack_check (const Stack_info *stack) {

    unsigned char flag = 0;

    if (stack == NULL)                                      flag = flag | INVALID_POINTER_FOR_STACK;

    if (stack->data[0] != KANAREIKA)                        flag = flag | BEGIN_KANAREIKA_NOT_FOUND;

    if (stack->data[stack->n_elements + 1] != KANAREIKA)    flag = flag | END_KANAREIKA_NOT_FOUND;

    if (stack->hash_sizes != hash_func_stack (stack))       flag = flag | HASH_STRUCT_STACK_MISMATCH;

    if (stack->hash_arr != hash_func_arr (stack))           flag = flag | HASH_DATA_ARRAY_MISMATCH;

    dump (flag);

    return (flag == 0);
}

void dump (unsigned char flag) {

    if (flag & INVALID_POINTER_FOR_STACK)   printf ("Invalid input pointer for stack *-*\n");

    if (flag & BEGIN_KANAREIKA_NOT_FOUND)   printf ("Kanareika in the beginning of data array is not found. Stack has been spoiled *-*\n");

    if (flag & END_KANAREIKA_NOT_FOUND)     printf ("Kanareika in the ending of data array is not found. Stack has been spoiled *-*\n");

    if (flag & HASH_STRUCT_STACK_MISMATCH)  printf ("Hash function of stack structure does not match the calculated one. Stack has been spoiled *-*\n");

    if (flag & HASH_DATA_ARRAY_MISMATCH)    printf ("Hash function of data array does not match the calculated one. Stack has been spoiled *-*\n");
}