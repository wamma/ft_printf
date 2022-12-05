/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heongjunpark <heongjunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:05:47 by heongjunpar       #+#    #+#             */
/*   Updated: 2022/12/06 06:45:32 by heongjunpar      ###   ########.fr       */
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
		ft_print_ptr(num / 16);
		ft_print_ptr(num % 16);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	print_memory;

	print_memory = 0;
	print_memory += write(1, "0x", 2);
	if (ptr == 0)
		print_memory += write(1, "0", 1);
	else
	{
		ft_cal_ptr(ptr);
		print_memory += ft_count_len(ptr);
	}
	return (print_memory);
}
