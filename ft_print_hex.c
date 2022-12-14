/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:15:37 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/08 16:56:46 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex(unsigned int num, char *str)
{
	int		i;
	char	result[16];
	int		len;

	i = 0;
	len = 0;
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		result[i] = str[num % 16];
		num /= 16;
		i++;
		len++;
	}
	i--;
	while (i >= 0)
	{
		if (ft_printf_char(result[i]) == -1)
			return (-1);
		i--;
	}
	return (len);
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num = -num;
		if (ft_printf_char('-') == -1)
			return (-1);
		len++;
	}
	if (num == 0)
	{
		if (ft_printf_char('0') == -1)
			return (-1);
		return (1);
	}
	if (format == 'x')
		len += ft_hex(num, "0123456789abcdef");
	else if (format == 'X')
		len += ft_hex(num, "0123456789ABCDEF");
	return (len);
}
