/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:42:01 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/08 16:52:06 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_format(va_list args, const char format)
{
	int	result;

	result = 0;
	if (format == 'c')
		result = ft_printf_char(va_arg(args, int));
	else if (format == 's')
		result = ft_print_str(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		result = ft_print_num(va_arg(args, int));
	else if (format == 'p')
		result = ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'u')
		result = ft_print_unsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		result = ft_print_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		result = ft_print_percent();
	return (result);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		result;
	int		tmp;
	va_list	args;

	i = 0;
	result = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			tmp = ft_format(args, format[i + 1]);
			if (tmp == -1)
				return (tmp);
			result += tmp;
			i++;
		}
		else
		{
			tmp = ft_printf_char(format[i]);
			if (tmp == -1)
				return (-1);
			result += tmp;
		}
		i++;
	}
	va_end(args);
	return (result);
}
