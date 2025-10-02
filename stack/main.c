#include "preambule.h"

int main () {

    size_t max_size;

    scanf ("%lu", &max_size);

    Stack_info stack;

    create_stack (&stack, max_size);

    int me = 0;

    for (int i = 0; i < 10; i++) {

        scanf ("%d", &me);
        push_back (&stack, me);
        print_stack (&stack);
    }

    // pop (&stack);

    free(stack.data);

    return 0;
}