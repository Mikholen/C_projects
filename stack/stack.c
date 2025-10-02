#include "preambule.h"

const int KANAREIKA = 9327645;
const int N_KANAREEK = 2;
const size_t INITIAL_SIZE = 48;

void create_stack (Stack_info *stack, const size_t max_size) {

    if (max_size <= 0) {

        printf ("Unable to create stack with maximum size <= 0 *-*\n");
    }

    else if (((sizeof (*stack)) != INITIAL_SIZE) || (stack == NULL)) {

        printf ("%lu\n", (sizeof (*stack)));

        printf ("Invalid input *-*\n");
    }

    else { 

        stack->n_elements = (size_t )0;
        stack->max_size = max_size;
        stack->data = (int *)calloc (N_KANAREEK, sizeof(int));
        stack->data[0] = stack->data[1] = KANAREIKA;
        stack->data_len = N_KANAREEK;

        stack->hash_sizes = hash_func_sizes (stack);
        stack->hash_arr = hash_func_arr (stack);
    }
}

size_t hash_func_sizes (const Stack_info *stack) {

    return (stack->n_elements + stack->max_size + stack->data_len);
}

int hash_func_arr (const Stack_info *stack) {

    int return_val = 0;

    for (size_t i = 1; i < stack->n_elements; i++) {

        return_val += stack->data[i];
    }

    return return_val;
}

void push_back (Stack_info *stack, const int element) {

    if (!stack_check (stack)) {

        printf ("Stack has been spoiled *-*\n");
    }

    else {

        if ((stack->n_elements + 1) > stack->max_size) {

            printf ("Stack overfull can not push element *-*\n");
        }

        else {

            if ((stack->n_elements + 1 + N_KANAREEK) > stack->data_len) {

                reallocate_memory (stack, (stack->n_elements + N_KANAREEK) * 2);
            }
            
            (stack->data)[stack->n_elements + N_KANAREEK - 1] = element;
            (stack->data)[stack->n_elements + N_KANAREEK] = KANAREIKA;
            stack->n_elements++;
        }
    }

    stack->hash_arr = hash_func_arr (stack);
    stack->hash_sizes = hash_func_sizes (stack);
}

int pop (Stack_info *stack) {

    if (!stack_check (stack)) {

        printf ("Stack has been spoiled *-*");
    }

    if (stack->n_elements == 0) {

        printf ("Stack is empty nothing to pop *-*\n");
        return 0;
    }

    else {

        reallocate_memory (stack, stack->n_elements + N_KANAREEK - 1);

        int value = stack->data[stack->n_elements];        
        stack->data[stack->n_elements] = KANAREIKA;
        stack->n_elements--;

        print_stack (stack);

        return value;
    }

    stack->hash_sizes = hash_func_sizes (stack);
    stack->hash_arr = hash_func_arr (stack);
}

void print_stack (const Stack_info *stack) {

    for (size_t i = 0; i < stack->n_elements + N_KANAREEK; i++) {

        printf ("%d ", stack->data[i]);
    }

    printf ("\n");
}

void reallocate_memory (Stack_info *stack, size_t new_len) {

    stack->data_len = new_len;
    stack->data = (int *)realloc (stack->data,new_len);
}

bool stack_check (const Stack_info *stack) {

    if ((stack->data[stack->n_elements + 1] == KANAREIKA) && (stack->data[0] == KANAREIKA) 
        && (stack->hash_arr == hash_func_arr (stack)) && (stack->hash_sizes == hash_func_sizes (stack))) {

            return true;
    }

    else {

        return false;
    }
}