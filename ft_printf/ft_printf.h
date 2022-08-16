/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talsaiaa <talsaiaa@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 01:32:40 by talsaiaa          #+#    #+#             */
/*   Updated: 2022/08/16 00:43:17 by talsaiaa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf_c(char c);
int		ft_printf_s(char *s);
int		ft_printf_u(unsigned int n);
void	ft_putchar(char c);
int		ft_printf_d(int n);
int		ft_printf_x(unsigned int n);
int		ft_printf_ux(unsigned int n);
int		ft_printf_p(unsigned long n);
int		ft_printf(const char *take_your_pick, ...);
int     ft_atoi(char *str);

#endif
