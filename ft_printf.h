/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungjup <hyungjup@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 13:36:20 by hyungjup          #+#    #+#             */
/*   Updated: 2022/12/06 11:45:39 by hyungjup         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

//ft_printf.c
int		ft_printf(const char *format, ...);
int		ft_printf_char(int c);
int		ft_format(va_list args, const char format);

//ft_printf_utils.c
int		ft_print_str(char *str);
int		ft_print_num(int n);
void	ft_putchar_fd(char c, int fd);
int		ft_print_percent(void);
void	ft_putstr_fd(char *s, int fd);

//ft_print_ptr.c
int		ft_count_len(unsigned long long num);
void	ft_cal_ptr(unsigned long long num);
int		ft_print_ptr(unsigned long long ptr);

//ft_print_unsigned.c
int		ft_num_length(unsigned int num);
char	*ft_unsigned_itoa(unsigned int n);
int		ft_print_unsigned(unsigned int n);

//ft_print_hex.c
int		ft_print_hex(unsigned int num, const char format);
void	ft_cal_hex(unsigned int num, const char format);

char	*ft_itoa(int n);

#endif