#ifndef STACK_PUSH
#define STACK_PUSH

bool Stack_Is_Full(const stack_t *stack);
void Stack_Size_Extend(stack_t *stack);
stack_err_t Stack_Push(stack_t *stack, int value);
void Stack_Fill(stack_t *stack);

#endif
