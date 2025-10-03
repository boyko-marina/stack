//! @file
//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <strings.h>

#include "stack.h"
#include "scan_data.h"
#include "calc_stack.h"

void Stack_Calc(stack_t *stack, char **ptr_text, int lines_num)
{
    // print_text(ptr_text, lines_num);
    for (int i = 0; i < lines_num; i++)
    {
        printf("current cmd: ");
        print_string(ptr_text[i]);
        // printf("%d\n", compare_strings(ptr_text[i], "ADD"));
        if (strncmp(ptr_text[i], "PUSH", 4) == 0)
        {
            int number = 0;// = Scan_Number(ptr_text[i]);
            sscanf(ptr_text[i], "PUSH %d", &number);
            // printf("%d", number);
            Stack_Push(stack, number);
        }
        else if (strncmp(ptr_text[i], "ADD", 3) == 0)
        {
            int num1 = 0;
            int num2 = 0;

            Stack_Pop(stack, &num1);
            Stack_Pop(stack, &num2);

            Stack_Push(stack, num1 + num2);

        }
        else if (strncmp(ptr_text[i], "SUB", 3) == 0)
        {
            int num1 = 0;
            int num2 = 0;

            Stack_Pop(stack, &num1);
            Stack_Pop(stack, &num2);

            int sub_result = 0;
            if (num1 > num2)
            {
                sub_result = num1 - num2;
            }
            else
            {
                sub_result = num2 - num1;
            }

            Stack_Push(stack, sub_result);
        }
        else if (strncmp(ptr_text[i], "MULT", 4) == 0)
        {
            int num1 = 0;
            int num2 = 0;

            Stack_Pop(stack, &num1);
            Stack_Pop(stack, &num2);

            Stack_Push(stack, num1 * num2);
        }
        else if (strncmp(ptr_text[i], "DIV", 3) == 0)
        {
            int num1 = 0;
            int num2 = 0;

            Stack_Pop(stack, &num1);
            Stack_Pop(stack, &num2);

            int div_result = 0;
            if (num1 > num2)
            {
                div_result = num1 / num2;
            }
            else
            {
                div_result = num2 / num1;
            }

            Stack_Push(stack, div_result);
        }
        else if (strncmp(ptr_text[i], "SQRT", 4) == 0)
        {
            int num = 0;
            Stack_Pop(stack, &num);
            Stack_Push(stack, (int) sqrt(num));
        }
        else if (strncmp(ptr_text[i], "OUT", 3) == 0)
        {
            int num = 0;
            Stack_Pop(stack, &num);

            printf("%d\n", num);
        }
        else if (strncmp(ptr_text[i], "HLT", 3) == 0)
        {
            Stack_Destroy(stack);
            break;
        }
        Stack_Print(stack);
        // print_string(ptr_text[i]);
    }
}

