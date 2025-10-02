//! @file
#include <TXLib.h>
#include <stdio.h>

#include "stack_pop.h"
#include "stack_init.h"
#include "stack_verify.h"


bool Stack_Is_Empty(const stack_t *stack)
{
    return stack->top == NULL_INDEX;
}

stack_err_t Stack_Pop(stack_t *stack, int *popped_num)
{
    STACK_VERIFY(stack);

    if (Stack_Is_Empty(stack))
    {
        printf("Error. Stack is empty. Can not pop the number to stack.\n");
        return STACK_EMPTY;
    }

    if (popped_num == NULL)
    {
        printf("Error with popped number.\n");
        return STACK_NOT_POP;
    }

    popped_num = stack->data[stack->top--];
//    stack->top --;

    STACK_VERIFY(stack);

    return STACK_OK;
}
