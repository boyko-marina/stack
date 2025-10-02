//! @file
#include <TXLib.h>
#include <stdio.h>

#include "stack_print.h"
#include "stack_init.h"

void Stack_Print(stack_t *stack)
{
    printf("%d ", stack->data[0])
    for (size_t i = 0, i < stack->top; i++)
    {
        printf("<- %d ", stack->data[i]);
    }
}
