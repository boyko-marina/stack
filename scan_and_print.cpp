//! @file
//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <ctype.h>
#include <limits.h>

#include "stack.h"
#include "scan_and_print.h"

int size_of_file(FILE *fp)
{
    long pos = ftell(fp);
    fseek(fp, 0L, SEEK_END);
    int n = ftell(fp);
    fseek(fp, pos, SEEK_SET);
    return n;
}

char *make_array(FILE *fp, int n)
{
    char *text = (char *) calloc(n + 1, sizeof(char));
    if (text == NULL)
    {
        printf("Error while making array.\n");
        return NULL;
    }

    size_t size_of_arr = fread(text, sizeof(char), n, fp);
    if (size_of_arr != (size_t) n)
    {
        printf("Error, the size of array isn't equal to the size of file.\n");
        return 0;
    }

    return text;
}

int num_of_lines(char *text, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        if (text[i] == '\n')
        {
            k++;
        }
    }
    return k;
}

char **point_array(char *text, int n, int k)
{
    char **ptr_text = (char **) calloc(k, sizeof(char *));

    if (ptr_text == NULL)
    {
        printf("Error while making pointer to the array.\n");
        return 0;
    }

    ptr_text[0] = &text[0];



    int j = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (text[i] == '\n')
        {
            j++;
            if (j < k)
            {
                ptr_text[j] = &text[i+1];
            }
            else
            {
                printf("The number of lines is bigger than numbers of pointer.");
                break;
            }
        }
    }

    return ptr_text;
}

void print_string(char *str)
{
    for (int i = 0; str[i] != '\n' && str[i] != '\0'; i++)
    {
        putchar(str[i]);
    }
    putchar('\n');
}

void print_text(char **ptr_text, int lines_num)
{
    for (int i = 0; i < lines_num; i++)
    {
        print_string(ptr_text[i]);
    }
}
