#include "preambule.h"

int main () {

    size_t max_size = 6;
    Stack_info stack = {};

    dump (create_stack (&stack, max_size));

    // stack.data[0] = 1;
    // stack.data[1] = 1;

    int me = 0;

    for (int i = 0; i < 2; i++) {

        scanf ("%d", &me);
        dump (push_back (&stack, me));
        print_stack (&stack);
        stack.data[0] = 1;

    }

    destructor (&stack);

    return 0;
}