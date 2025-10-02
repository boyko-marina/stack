//! @file
#include <TXLib.h>
#include <stdio.h>

#include "stack_destroy.h"
#include "stack_verify.h"
#include "stack_init.h"

stack_err_t Stack_Destroy(stack_t *stack)
{
    STACK_VERIFY(stack);

    free (stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;

    return STACK_OK;
}
