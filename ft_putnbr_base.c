/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:43:39 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/08 17:05:15 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(long long num)
{
	int		i;
	char	result[10];
	int		len;

	i = 0;
	len = 0;
	if (num < 0)
	{
		num = -num;
		if (ft_printf_char('-') == -1)
			return (-1);
		len++;
	}
	while (num > 0)
	{
		result[i] = "0123456789"[num % 10];
		num /= 10;
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
