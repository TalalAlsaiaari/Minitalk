/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talal_alsaiaary@yahoo.comr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 23:45:52 by talsaiaa          #+#    #+#             */
/*   Updated: 2021/11/02 23:45:53 by talsaiaa         ###   ########.AD       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char c)
{
	write (1, &c, 1);
	return (1);
}