/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 16:41:42 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/08/13 17:25:21 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

int counter = 0;

void siggs(int sig)
{
    int bin[6];
    int x;
    int res;
    int sum;
    
    x = 0;
    res = 0;
    sum = 0;
    if (sig == SIGUSR1)
        bin[counter] = 1;
    else if (sig == SIGUSR2)
        bin [counter] = 0;
    counter++;
    if (counter == 6)
    {
        while (x < counter)
        {
            res = (sum + bin[x]) * 2;
            sum = res + bin[x + 1];
            x++;
        }
        counter = 0;
        write (1, &sum, 1);
    }
}

int main ()
{
    struct sigaction sa;
    sa.sa_handler = &siggs;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    printf("PID: %d\n", getpid());
    while (1)
        pause();
}