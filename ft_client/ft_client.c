#include "../include/minitalk.h"

void converter(char **av, int x)
{
    int counter;
    int y;
    
    counter = 1;
    y = 64;
    while (counter <= 7)
    {
        if(av[2][x] >= y)
        {
            kill(ft_atoi(av[1]), SIGUSR1);
            av[2][x] = av[2][x] - y;
            y = y/2;
        }
        else
        {
            kill(ft_atoi(av[1]), SIGUSR2);
            y = y/2;
        }
        counter++;
        usleep(100);
    }
}

int main(int ac, char **av)
{
    int x;
    
    x = 0;
    if (ac != 3)
        ft_printf("Number of arguments is incorrect!\n");

    else
    {
        while (av[2][x])
        {
            converter(av, x);
            x++;
        }
    }
    return(0);
}