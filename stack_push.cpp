//! @file
#include <TXLib.h>
#include <stdio.h>
#include <limits.h>

#include "stack_push.h"
#include "stack_init.h"
#include "stack_verify.h"

bool Stack_Is_Full(const stack_t *stack)
{
    return stack->top == (int) stack->capacity - 1;
}

void Stack_Size_Extend(stack_t *stack)
{
    // for (int i = 0; i < stack->capacity; i++)
    // {
    //     printf("%d ", stack->data[i]);
    // }
    // putchar('\n');

    int *new_ptr = NULL;
    size_t new_capacity = stack->capacity * 2;
    new_ptr = (int *) realloc(stack->data, new_capacity * sizeof(int));

    if (new_ptr == NULL)
    {
        printf("ERROR. REALLOC.\n");
    }

    stack->data = new_ptr;

    for (size_t i = stack->capacity; i < new_capacity; i++)
    {
        stack->data[i] = INT_MAX; // poison - huge const
    }

    stack->capacity = new_capacity;

    // for (int i = 0; i < stack->capacity; i++)
    // {
    //     printf("%d ", stack->data[i]);
    // }
    // putchar('\n');
}

stack_err_t Stack_Push(stack_t *stack, int value)
{
    STACK_VERIFY(stack);

    if (!isalpha(value))
    {
        printf("Error. Wrong symbol was entered.\n");
    }

    if (Stack_Is_Full(stack))
    {
        Stack_Size_Extend(stack);
    }

    stack->data[++stack->top] = value;

    STACK_VERIFY(stack);
    return STACK_OK;
}


void Stack_Fill(stack_t *stack)
{
    int number = 0;
    while (scanf("%d", &number) == 1 && number != '#')
    {
        if (Stack_Push(stack, number) != STACK_OK)
        {
            printf("Error. Can not push that number -> %d.\n", number);
        }
    }
}
