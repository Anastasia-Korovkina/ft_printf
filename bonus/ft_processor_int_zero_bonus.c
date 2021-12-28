/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_int_zero.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:12:11 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 15:15:23 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_int_zero3(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	if (s_flags->space)
		s_flags->width--;
	if (s_flags->precision)
		ft_putnbr(copy_arg, len);
	else
		s_flags->width++ ;
	if ((s_flags->precision <= 1) || s_flags->plus)
		s_flags->width--;
	while ((s_flags->width)-- > len_num)
		ft_putchar(' ', len);
}

void	ft_processor_int_zero1(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->plus)
	{
		ft_putchar('+', len);
		s_flags->width--;
	}
	if (s_flags->precision > len_num)
	{
		while ((s_flags->precision)-- > len_num + 1)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
		ft_processor_int_zero3(s_flags, copy_arg, len_num, len);
}

void	ft_processor_int_zero4(t_flags *s_flags, int len_num, int *len)
{
	if ((s_flags->precision <= 0) || s_flags->plus)
		s_flags->width--;
	if (s_flags->zero)
	{
		s_flags->width--;
		if (!s_flags->space)
			s_flags->width++;
		if (s_flags->plus)
		{
			ft_putchar('+', len);
			s_flags->width--;
		}
		while ((s_flags->width)-- > len_num)
			ft_putchar('0', len);
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		if (s_flags->plus)
			ft_putchar('+', len);
	}
}

void	ft_processor_int_zero2(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	if (s_flags->precision >= len_num)
	{
		while ((s_flags->width)-- > s_flags->precision)
			ft_putchar(' ', len);
		if (s_flags->plus)
			ft_putchar('+', len);
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
	}
	else
	{
		ft_processor_int_zero4(s_flags, len_num, len);
		ft_putnbr(copy_arg, len);
	}
}
