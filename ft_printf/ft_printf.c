/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talal_alsaiaary@yahoo.comr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 00:54:59 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/11/02 23:43:45 by talsaiaa         ###   ########.AD       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	normie(const char *take_your_pick, va_list pick, int i, int counter)
{
	if (take_your_pick[i] == 'c')
		counter += ft_printf_c(va_arg(pick, int));
	else if (take_your_pick[i] == 's')
		counter += ft_printf_s(va_arg(pick, char *));
	else if (take_your_pick[i] == 'p')
		counter += ft_printf_p(va_arg(pick, unsigned long));
	else if (take_your_pick[i] == 'd' || take_your_pick[i] == 'i')
		counter += ft_printf_d(va_arg(pick, int));
	else if (take_your_pick[i] == 'u')
		counter += ft_printf_u(va_arg(pick, unsigned int));
	else if (take_your_pick[i] == 'x')
		counter += ft_printf_x(va_arg(pick, unsigned int));
	else if (take_your_pick[i] == 'X')
		counter += ft_printf_ux(va_arg(pick, unsigned int));
	else if (take_your_pick[i] == '%')
		counter += ft_printf_c('%');
	return (counter);
}

int	ft_printf(const char *take_your_pick, ...)
{
	va_list	pick;
	int		counter;
	int		i;

	i = 0;
	counter = 0;
	va_start(pick, take_your_pick);
	while (take_your_pick[i])
	{
		if (take_your_pick[i] != '%')
			counter += ft_printf_c(take_your_pick[i]);
		if (take_your_pick[i] == '%')
		{
			i++;
			counter = normie(take_your_pick, pick, i, counter);
		}
		i++;
	}
	va_end(pick);
	return (counter);
}
