/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_int.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:41 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 15:33:25 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_int_pos1(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->plus)
		ft_putchar('+', len);
	if (s_flags->precision > len_num)
	{
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
	{
		if (s_flags->space)
			s_flags->width--;
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
}

void	ft_processor_int_pos3(t_flags *s_flags, int len_num, int *len)
{
	if (s_flags->zero && s_flags->precision == -1)
	{
		if ((s_flags->precision < s_flags->width) || s_flags->plus)
			s_flags->width--;
		if (!s_flags->space)
			s_flags->width++;
		if (s_flags->plus)
			ft_putchar('+', len);
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

void	ft_processor_int_pos2(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	if (s_flags->precision >= len_num)
	{
		if ((s_flags->precision == s_flags->width) || s_flags->plus)
			s_flags->width--;
		while ((s_flags->width)-- > s_flags->precision)
			ft_putchar(' ', len);
		if (s_flags->plus)
			ft_putchar('+', len);
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
	}
	else
		ft_processor_int_pos3(s_flags, len_num, len);
	ft_putnbr(copy_arg, len);
}

void	ft_processor_int_sub(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	if (copy_arg > 0)
	{
		if (s_flags->minus)
			ft_processor_int_pos1(s_flags, copy_arg, len_num, len);
		else
			ft_processor_int_pos2(s_flags, copy_arg, len_num, len);
	}
	else if (copy_arg < 0)
	{
		if (s_flags->minus)
			ft_processor_int_neg1(s_flags, copy_arg, len_num, len);
		else
			ft_processor_int_neg2(s_flags, copy_arg, len_num, len);
	}
	else
	{
		if (s_flags->minus)
			ft_processor_int_zero1(s_flags, copy_arg, len_num, len);
		else
			ft_processor_int_zero2(s_flags, copy_arg, len_num, len);
	}
}

void	ft_processor_int(t_flags *s_flags, va_list	*argptr, int *len)
{
	int	copy_arg;
	int	len_num;

	copy_arg = va_arg(*argptr, int);
	len_num = ft_len_int(copy_arg);
	if (copy_arg >= 0 && s_flags->space)
		ft_putchar(' ', len);
	ft_processor_int_sub(s_flags, copy_arg, len_num, len);
}
