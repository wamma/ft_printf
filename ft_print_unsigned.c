/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:43:00 by heongjunpar       #+#    #+#             */
/*   Updated: 2022/12/08 16:58:25 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int num)
{
	int		i;
	char	result[10];
	int		len;

	i = 0;
	len = 0;
	if (num == 0)
	{
		if (ft_printf_char('0') == -1)
			return (-1);
		return (1);
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
