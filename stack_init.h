#ifndef STACK_INIT
#define STACK_INIT

typedef struct stack {
    int *data;
    int top;
    size_t capacity;
} stack_t;

stack_err_t Stack_Init(stack_t *stack, size_t capacity);


#endif
