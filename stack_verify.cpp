//! @file
#include <TXLib.h>
#include <stdio.h>

#include "stack_init.h"
#include "stack_pop.h"
#include "stack_dump.h"
#include "stack_verify.h"

stack_err_t Stack_Verify(stack_t *stack)
{
    if (stack == NULL)
    {
        return STACK_NULL_PTR;
    }

    stack_err_t err = STACK_OK;

    if (stack->data == NULL)
    {
        return STACK_DATA_NULL;
    }

    if (stack->top < NULL_INDEX)
    {
        return STACK_EMPTY;
    }

    return err;
}

stack_err_t STACK_VERIFY(stack_t *stack)
{
    stack_err_t err = Stack_Verify(stack);
    if (err != STACK_OK)
    {
        Stack_Dump(stack);
    }
    return err;
}
