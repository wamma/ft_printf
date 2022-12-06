/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 10:15:37 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/06 15:42:26 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hex(unsigned int num)
{
	int	cnt;

	cnt = 0;
	while (num != 0)
	{
		cnt++;
		num /= 16;
	}
	return (cnt);
}

void	ft_cal_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_cal_hex(num / 16, format);
		ft_cal_hex(num % 16, format);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	int	hex_cnt;

	hex_cnt = ft_count_hex(num);
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_cal_hex(num, format);
	return (hex_cnt);
}
