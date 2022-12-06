/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 06:43:00 by heongjunpar       #+#    #+#             */
/*   Updated: 2022/12/06 15:00:41 by hyungjup         ###   ########.fr       */
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

char	*ft_unsigned_itoa(unsigned int n)
{
	char	*num;
	int		length;

	length = ft_num_length(n);
	num = (char *)malloc(sizeof(char) * (length + 1));
	if (!num)
		return (NULL);
	num[length] = '\0';
	length--;
	while (n != 0)
	{
		num[length] = n % 10 + '0';
		n /= 10;
		length--;
	}
	return (num);
}

int	ft_print_unsigned(unsigned int n)
{
	int		print_num;
	char	*num;

	print_num = 0;
	if (n == 0)
		print_num += write(1, "0", 1);
	else
	{
		num = ft_unsigned_itoa(n);
		print_num += ft_print_str(num);
		free(num);
	}
	return (print_num);
}
