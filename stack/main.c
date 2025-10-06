#include "preambule.h"

int main () {

    size_t max_size = 10;
    Stack_info stack = {};

    create_stack (&stack, max_size);

    // stack.data[0] = 1;
    // stack.data[1] = 1;

    int me = 0;

    for (int i = 0; i < 2; i++) {

        scanf ("%d", &me);
        push_back (&stack, me);
        print_stack (&stack);
    }

    // stack.data[0] = 1;
    // stack.data[stack.n_elements + 1] = 1;

    // for (int i = 0; i < 2; i++) {

    //     stack.max_size = 100;
    //     stack.data[1] = 3;
    //     scanf ("%d", &me);
    //     push_back (&stack, me);
    //     print_stack (&stack);
    // }

    destructor (&stack);

    return 0;
}