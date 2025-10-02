#ifndef STACK_POP
#define STACK_POP

#define NULL_INDEX -1
bool Stack_Is_Empty(const stack_t *stack);
stack_err_t Stack_Pop(stack_t *stack);


#endif
