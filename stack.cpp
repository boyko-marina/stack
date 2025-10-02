//! @file
//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

#include "stack.h"

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

    // if (!isalpha(value))
    // {
    //     printf("Error. Wrong symbol was entered.\n");
    // }

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
    while (1)
    {
        int symbol = scanf("%d", &number);
        if (symbol == 1)
        {
            if (Stack_Push(stack, number) != STACK_OK)
            {
                printf("Error. Can not push that number -> %d.\n", number);
            }
        }
        else
        {
            printf("All numbers are entered.\n");
            break;
        }
    }


    // while (scanf("%d", &number) == 1 && number != '#')
    // {
    //     if (Stack_Push(stack, number) != STACK_OK)
    //     {
    //         printf("Error. Can not push that number -> %d.\n", number);
    //     }
    // }
}

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

    *popped_num = stack->data[stack->top];
    stack->top--;

    STACK_VERIFY(stack);

    return STACK_OK;
}

stack_err_t Stack_Destroy(stack_t *stack)
{
    STACK_VERIFY(stack);

    free (stack->data);
    stack->data = NULL;
    stack->top = -1;
    stack->capacity = 0;

    return STACK_OK;
}

void Stack_Dump(stack_t *stack)
{
    printf("--- STACK DUMP ---");

    if (stack == NULL)
    {
        printf("Stack pointer is NULL.\n");
    }

    printf("Size of the stack: %d.\n", stack->top);
    printf("Capacity of the stack: %d\n", (int) stack->capacity);

    if (stack->data != NULL)
    {
        printf("Data pointer of the stack: %p.\n", stack->data);
        printf("Data of the stack:\n");
        printf("Index           Value\n");
        for (int i = 0; i < stack->top; i++)
        {
            printf("[%d]           %d\n", i, stack->data[i]);
        }
    }
    else
    {
        printf("Data pointer of the stack in NULL.\n");
    }

    printf("---------\n");
}

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

void Stack_Print(stack_t *stack)
{
    printf("%d ", stack->data[0]);
    for (int i = 1; i <= stack->top; i++)
    {
        printf("<- %d ", stack->data[i]);
    }

    putchar('\n');
}
