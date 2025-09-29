#include "preambule.h"

const int KANAREIKA = 9327645;
const int N_KANAREEK = 2;

void create_stack (Stack_info *stack, size_t max_size) {

    (*stack).n_elements = (size_t )0;
    (*stack).max_size = max_size;
    (*stack).hash = hash_function ((*stack).n_elements, (*stack).max_size);
    int *arr = (int *)calloc (N_KANAREEK, sizeof(int));
    arr[0] = arr[1] = KANAREIKA;
    (*stack).data = arr;
    (*stack).data_len = N_KANAREEK;
}

long long int hash_function (size_t n_elements, size_t max_size) {

    return llabs (n_elements * (max_size - (n_elements % max_size)) + 81);
}

void push_back (Stack_info *stack, int element) {

    if (((*stack).n_elements + 1) > (*stack).max_size) {

        printf ("Stack overfull can not push element *-*\n");
    }

    else if (((*stack).n_elements + 1 + N_KANAREEK) > (*stack).data_len) {

        (*stack).data_len = ((*stack).n_elements + N_KANAREEK) * 2;

        int *arr = (int *)calloc (((*stack).n_elements + N_KANAREEK) * 2, sizeof(int));
        for (size_t i = 0; i < (*stack).n_elements + N_KANAREEK; i++) {

            arr[i] = (*stack).data[i];
        }
        
        arr[(*stack).n_elements + 1] = element;
        arr[(*stack).n_elements + 2] = KANAREIKA;
        (*stack).n_elements++;

        free((*stack).data);
        (*stack).data = arr;
    } 

    else {

        (*stack).data[(*stack).n_elements + 1] = element;
        (*stack).data[(*stack).n_elements + 2] = KANAREIKA;
        (*stack).n_elements++;
    }
}

int pop (Stack_info *stack) {

    if ((*stack).n_elements == 0) {

        printf ("Stack is empty nothing to pop *-*");
        return 0;
    }

     else {

        int value = (*stack).data[(*stack).n_elements];

        int *arr = (int *)calloc (((*stack).n_elements + N_KANAREEK) - 1, sizeof(int));
        for (size_t i = 0; i < (*stack).n_elements + N_KANAREEK - 2; i++) {

            arr[i] = (*stack).data[i];
        }
        
        arr[(*stack).n_elements] = KANAREIKA;
        (*stack).n_elements--;

        free((*stack).data);
        (*stack).data = arr;

        print_stack (stack);

        return value;
    }
}

void print_stack (Stack_info *stack) {

    for (size_t i = 0; i < (*stack).n_elements + 2; i++) {

        printf ("%d ", (*stack).data[i]);
    }

    printf ("\n");
}