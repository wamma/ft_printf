/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:47:36 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/08 16:36:28 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	while (str[i])
		i++;
	tmp = write(1, str, i);
	return (tmp);
}

int	ft_print_str(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[i])
	{
		tmp = write(1, &str[i], 1);
		if (tmp == -1)
			return (-1);
		i++;
	}
	return (i);
}

int	ft_print_num(int n)
{
	int	len;

	if (n == 0)
	{
		if (ft_printf_char('0') == -1)
			return (-1);
		len = 1;
	}
	else
		len = ft_putnbr_base((long long)n);
	return (len);
}

int	ft_print_percent(void)
{
	int	tmp;

	tmp = ft_printf_char('%');
	if (tmp == -1)
		return (-1);
	return (1);
}
