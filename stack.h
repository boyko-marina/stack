#ifndef STACK_H
#define STACK_H

#define NULL_INDEX -1

typedef struct stack {
    int *data;
    int top;
    size_t capacity;
} stack_t;

typedef enum{
    STACK_OK = 0,
    STACK_NULL_PTR = 1,
    STACK_DATA_NULL = 1,
    STACK_EMPTY = 1,
    STACK_NOT_POP = 1,
} stack_err_t;

stack_err_t Stack_Init(stack_t *stack, size_t capacity);
void Stack_Dump(stack_t* stack);
stack_err_t Stack_Destroy(stack_t *stack);
bool Stack_Is_Empty(const stack_t *stack);
stack_err_t Stack_Pop(stack_t *stack, int *popped_num);
void Stack_Print(stack_t *stack);
bool Stack_Is_Full(const stack_t *stack);
void Stack_Size_Extend(stack_t *stack);
stack_err_t Stack_Push(stack_t *stack, int value);
void Stack_Fill(stack_t *stack);
stack_err_t Stack_Verify(stack_t *stack);
stack_err_t STACK_VERIFY(stack_t *stack);
void Stack_Example();

#endif
