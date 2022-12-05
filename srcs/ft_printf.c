/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:01 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/05 18:55:12 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	cnt;

	cnt = 0;
	if (format == 'c')
		cnt += ft_print_c(va_arg(args, int));
	else if (format == 's')
		cnt += ft_print_s(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		cnt += ft_print_n(va_arg(args, int));
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	args;
	int		cnt;

	i = 0;
	cnt = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			cnt += ft_format(args, format[i + 1]);
			i++;
		}
		else
			cnt += ft_print_c(format[i]);
		i++;
	}
	va_end(args);
	return (cnt);
}
