/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heongjunpark <heongjunpark@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:43:00 by heongjunpar       #+#    #+#             */
/*   Updated: 2022/12/06 06:53:41 by heongjunpar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_num_length(unsigned int num)
{
	int	cnt;

	cnt = 0;
	while (num != 0)
	{
		cnt++;
		num /= 10;
	}
	return (cnt);
}

char	*ft_unsitned_itoa(unsigned int n)
{
	char	*num;
	int		length;

	length = ft_num_length(n);
	num = (char *)malloc(sizeof(char) * (length + 1));
	if (!num)
		return (NULL);
	num[length] = '\0';
	while (n != 0)
	{
		num[length - 1] = n % 10 + '0';
		n /= 10;
		length--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_num;
	char	*num;

	if (n == 0)
		print_num += write(1, "0", 1);
	print_num = 0;
	else
	{
		num = ft_unsigned_itoa(n);
		print_num += ft_print_str(num);
		free(num);
	}
	return (print_num);
}
