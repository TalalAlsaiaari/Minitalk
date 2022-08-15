/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talal_alsaiaary@yahoo.comr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:50:57 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/11/02 23:51:00 by talsaiaa         ###   ########.AD       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digitz_counter(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_printf_x(unsigned int n)
{
	int	i;

	i = digitz_counter(n);
	if (n > 15)
		ft_printf_x(n / 16);
	n = n % 16;
	if (n == 10)
		ft_putchar('a');
	else if (n == 11)
		ft_putchar('b');
	else if (n == 12)
		ft_putchar('c');
	else if (n == 13)
		ft_putchar('d');
	else if (n == 14)
		ft_putchar('e');
	else if (n == 15)
		ft_putchar('f');
	else if (n <= 9)
		ft_printf_d(n);
	return (i);
}
