/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talal_alsaiaary@yahoo.comr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:48:51 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/11/02 23:48:54 by talsaiaa         ###   ########.AD       */
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

int	ft_printf_ux(unsigned int n)
{
	int	i;

	i = digitz_counter(n);
	if (n > 15)
		ft_printf_ux(n / 16);
	n = n % 16;
	if (n == 10)
		ft_putchar('a' - 32);
	else if (n == 11)
		ft_putchar('b' - 32);
	else if (n == 12)
		ft_putchar('c' - 32);
	else if (n == 13)
		ft_putchar('d' - 32);
	else if (n == 14)
		ft_putchar('e' - 32);
	else if (n == 15)
		ft_putchar('f' - 32);
	else if (n <= 9)
		ft_printf_d(n);
	return (i);
}
