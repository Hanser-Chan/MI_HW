#include <stdio.h>

int check1()
{
    int i = 1;
    char *pi = (char *)&i;
    return *pi == 0;
}

int main()
{
    if (check1() == 1)
    {
        printf("big\n");
    }
    else
    {
        printf("little\n");
    }
    return 0;
}