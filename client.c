/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:52:10 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/08/13 17:21:40 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>


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
            kill(atoi(av[1]), SIGUSR1);
            av[2][x] = av[2][x] - y;
            y = y/2;
        }
        else
        {
            kill(atoi(av[1]), SIGUSR2);
            y = y/2;
        }
        usleep(100);
        counter++;
    }
}

int main(int ac, char **av)
{
    int x;
    
    x = 0;
    if (ac != 3)
        printf("Number of arguments is incorrect!\n");

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