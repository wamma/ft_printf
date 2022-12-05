/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heongjunpark <heongjunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:01 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/06 06:45:48 by heongjunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	cnt;

	cnt = 0;
	if (format == 'c')
		cnt += ft_print_char(va_arg(args, int));
	else if (format == 's')
		cnt += ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		cnt += ft_print_num(va_arg(args, int));
	else if (format == 'p')
		cnt += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		cnt += ft_print_unsigned(va_arg(args, unsigned int));
}

int	ft_printf(const char *format, ...)
{
	int	i;
	int	cnt;
	va_list	args;

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
