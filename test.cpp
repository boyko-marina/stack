//#include <TXLib.h>
#include <stdio.h>
#include <stdlib.h>

int main( )
{
    int n = 0;
    int d = scanf("%d", &n);
    if (d == 1)
    {
        printf("ok");
    }
    else if (d == 0)
    {
        // if (n == '#')
        // {
        //     printf("# is ok");
        // }
        printf("%d", n);
        printf("%s", n);
        // else
        // {
        //     printf("error");
        // }
    }
}
