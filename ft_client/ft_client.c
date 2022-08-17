/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 00:15:20 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/08/18 01:10:09 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	converter(char **av, int x)
{
	int	counter;
	int	y;

	counter = 1;
	y = 64;
	while (counter <= 7)
	{
		if (av[2][x] >= y)
		{
			kill(ft_atoi(av[1]), SIGUSR1);
			av[2][x] = av[2][x] - y;
			y = y / 2;
		}
		else
		{
			kill(ft_atoi(av[1]), SIGUSR2);
			y = y / 2;
		}
		counter++;
		usleep(30);
	}
}

int	main(int ac, char **av)
{
	int	x;

	x = 0;
	if (ac != 3)
		ft_printf("Number of arguments is incorrect!\n");
	if (ft_atoi(av[1]) <= 0)
		ft_printf("Invalid PID!\n");
	else
	{
		while (av[2][x])
		{
			converter(av, x);
			x++;
		}
	}
	return (0);
}
