//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <math.h>

#include "stack.h"
#include "scan_data.h"
#include "calc_stack.h"


int main( )
{
    FILE *fp = fopen("calc_stack.txt", "rb");
    if (fp == 0)
    {
//        printf("Error while opening file.\n");
    }

    int file_size = size_of_file(fp);
    char *text = make_array(fp, file_size);

//    printf("%d\n", file_size);

    int lines_num = num_of_lines(text, file_size);
    char **ptr_text = point_array(text, file_size, lines_num);

//    printf("%d\n", lines_num);

    stack_t stack = {};

    if (Stack_Init(&stack, 10) != STACK_OK)
    {
        printf("Error. Can not initialize stack.\n");
    }
//    printf("init_ok\n");

    Stack_Calc(&stack, ptr_text, lines_num);
 //   printf("calc_ok\n");
    // Stack_Example();
    return 0;
}

