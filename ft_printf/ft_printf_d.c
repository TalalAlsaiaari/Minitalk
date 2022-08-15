/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talal_alsaiaary@yahoo.comr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:46:19 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/11/02 23:46:23 by talsaiaa         ###   ########.AD       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digits_counter(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		i = 1;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

int	ft_printf_d(int n)
{
	int	i;

	i = digits_counter(n);
	if (n == -2147483648)
	{
		ft_printf_d(n / 10);
		ft_putchar('8');
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_printf_d(-n);
	}
	else
	{
		if (n > 9)
			ft_printf_d(n / 10);
		ft_putchar(48 + n % 10);
	}
	return (i);
}
