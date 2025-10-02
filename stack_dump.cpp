//! @file
#include <TXLib.h>
#include <stdio.h>

#include "stack_dump.h"
#include "stack_init.h"


void Stack_Dump(stack_t *stack)
{
    printf("--- STACK DUMP ---");

    if (stack == NULL)
    {
        printf("Stack pointer is NULL.\n");
    }

    printf("Size of the stack: %zu.\n", stack->top);
    printf("Capacity of the stack: %zu.\n", stack->capacity);

    if (stack->data != NULL)
    {
        printf("Data pointer of the stack: %p.\n", stack->data);
        printf("Data of the stack:\n");
        printf("Index           Value\n");
        for (size_t i = 0; i < stack->top; i++)
        {
            printf("[%zu]           %d\n", i, stack->data[i]);
        }
    }
    else
    {
        printf("Data pointer of the stack in NULL.\n");
    }

    printf("---------\n");
}
