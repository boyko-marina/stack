//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>

#include "stack.h"

int main( )
{
    stack_t stack = {};

    if (Stack_Init(&stack, 10) != STACK_OK)
    {
        printf("Error. Can not initialize stack.\n");
    }

    printf("Enter the numbers you want to place in the stack. Enter '#' to stop the entering.\n");
    Stack_Fill(&stack);

    Stack_Print(&stack);

    int popped_num = 0;
    for (size_t i = 0; i < 5; i++)
    {
        if (Stack_Pop(&stack, &popped_num) != STACK_OK)
        {
            printf("Error. Can not pop that number -> %d.\n", popped_num);
        }
        printf("%d ", popped_num);
    }
    putchar('\n');

    Stack_Print(&stack);

    Stack_Destroy(&stack);
    return 0;
}

