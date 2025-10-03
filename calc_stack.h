#ifndef CALC_STACK
#define CALC_STACK

#include "stack.h"

int str_len(const char *s);
// int Scan_Number(const char *str);
void Stack_Calc(stack_t *stack, char **ptr_text, int lines_num);
// int compare_strings(const char *par1, const char *par2);
void print_string(char *str);
void print_text(char **ptr_text, int lines_num);

#endif
