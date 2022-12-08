/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:05:47 by heongjunpar       #+#    #+#             */
/*   Updated: 2022/12/08 16:57:09 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_len(unsigned long long num)
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

void	ft_cal_ptr(unsigned long long num)
{
	if (num >= 16)
	{
		ft_cal_ptr(num / 16);
		ft_cal_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			ft_printf_char((num + '0'));
		else
			ft_printf_char((num - 10 + 'a'));
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_memory;

	print_memory = 0;
	print_memory = ft_print_str("0x");
	if (print_memory == -1)
		return (-1);
	if (ptr == 0)
	{
		print_memory = ft_printf_char('0');
		if (print_memory == -1)
			return (-1);
		return (3);
	}
	else
	{
		ft_cal_ptr(ptr);
		print_memory += ft_count_len(ptr);
	}
	return (print_memory);
}
