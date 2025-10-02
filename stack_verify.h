#ifndef STACK_VERIFY_F
#define STACK_VERIFY_F

typedef enum{
    STACK_OK = 0,
    STACK_NULL_PTR = 1,
    STACK_DATA_NULL = 1,
    STACK_EMPTY = 1,
    STACK_NOT_POP = 1,
} stack_err_t;

stack_err_t Stack_Verify(stack_t *stack);
stack_err_t STACK_VERIFY(stack_t *stack);

// #define STACK_VERIFY(stack)
//     stack_err_t err = Stack_Verify(stack);
//     if (err != STACK_OK)
//     {
//         Stack_Dump(stack);
//         return err;
//     }

#endif
