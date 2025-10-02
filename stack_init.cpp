//! @file
#include <TXLib.h>
#include <stdio.h>

#include "stack_init.h"
#include "stack_verify.h"


stack_err_t Stack_Init(stack_t *stack, size_t capacity)
{
    if (stack == NULL || capacity == 0)
    {
        return STACK_NULL_PTR;
    }

    stack->capacity = capacity;
    stack->data = (int *) calloc(stack->capacity, sizeof(int));
    stack->top = -1;

    if (stack->data == NULL)
    {
        return STACK_DATA_NULL;
    }

    return STACK_OK;
}
