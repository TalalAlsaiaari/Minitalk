/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:40:07 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/08/16 19:09:05 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int counter = 0;

void siggs(int sig)
{
    int bin[7];
    int x;
    int sum;
    
    x = 0;
    sum = 0;
    if (sig == SIGUSR1)
        bin[counter] = 1;
    else if (sig == SIGUSR2)
        bin[counter] = 0;
    counter++;
    if (counter == 7)
    {
        while (x < counter)
        {
            sum = (sum * 2) + bin[x];
            x++;
        }
        counter = 0;
        write(1, &sum, 1);
    }
}

int main ()
{
    struct sigaction sa = {0};
    sa.sa_handler = &siggs;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    ft_printf("PID: %d\n", getpid());
    while (1)
        pause();
}