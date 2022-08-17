/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_server.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:40:07 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/08/18 00:52:49 by talsaiaa         ###   ########.AD       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	g_counter = 0;

void	siggs(int sig)
{
	int	bin[7];
	int	x;
	int	sum;

	x = 0;
	sum = 0;
	if (sig == SIGUSR1)
		bin[g_counter] = 1;
	else if (sig == SIGUSR2)
		bin[g_counter] = 0;
	g_counter++;
	if (g_counter == 7)
	{
		while (x < g_counter)
		{
			sum = (sum * 2) + bin[x];
			x++;
		}
		g_counter = 0;
		write(1, &sum, 1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sa.sa_handler = &siggs;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("PID: %d\n", getpid());
	while (1)
		pause();
}
