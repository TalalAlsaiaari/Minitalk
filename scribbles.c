#include <stdio.h>

void converter(char **av, int x)
{
    int counter;
    int y;
    int z;
    
    counter = 1;
    y = 64;
    z = 0;
    while (counter <= 7)
    {
        if(av[1][x] >= y)
        {
            z = 1;
            av[1][x] = av[1][x] - y;
            y = y/2;
            printf("%d\n", z);
        }
        else
            {
                z = 0;
                y = y/2;
                printf("%d\n", z);
            }
        counter++;
    }
}

int main(int ac, char** av)
{
    int x;
    
    x = 0;
    if (ac != 2)
        printf("nah B\n");
    else
    {
        while (av[1][x])
        {
            converter(av, x);
            printf("\n");
            x++;
        }
    }
    return (0);
}