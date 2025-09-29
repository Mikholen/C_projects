#include <stdio.h>
#include "preambule.h"

int main () {

    size_t max_size;

    scanf ("%lu", &max_size);

    Stack_info stack;
    create_stack (&stack, max_size);

    return 0;
}