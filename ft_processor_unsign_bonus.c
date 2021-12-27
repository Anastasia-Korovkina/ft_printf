/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_unsign_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:46:37 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 19:02:38 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_unsign_1(t_flags *s_flags, unsigned int copy_arg,
int len_num, int *len)
{
	int				fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision >= len_num)
	{
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
		if (copy_arg != 0)
			ft_putunsign(copy_arg, len);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
	{
		if (copy_arg == 0 && s_flags->precision == -1)
		{
			ft_putunsign(copy_arg, len);
			s_flags->width--;
		}
		else if (copy_arg > 0)
			ft_putunsign(copy_arg, len);
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
}

void	ft_processor_unsign_2(t_flags *s_flags, unsigned int copy_arg,
int len_num, int *len)
{
	if (copy_arg == 0 && s_flags->precision == -1)
		s_flags->width--;
	if (s_flags->precision > len_num)
	{
		while ((s_flags->width)-- > s_flags->precision)
			ft_putchar(' ', len);
		if (copy_arg == 0 && s_flags->precision > -1)
			s_flags->precision--;
		while ((s_flags->precision)-- > len_num)
			ft_putchar('0', len);
	}
	else
	{
		if (s_flags->zero && s_flags->precision == -1)
			while ((s_flags->width)-- > len_num)
				ft_putchar('0', len);
		else
			while ((s_flags->width)-- > len_num)
				ft_putchar(' ', len);
	}
	if ((copy_arg == 0 && s_flags->precision == -1) || copy_arg > 0)
		ft_putunsign(copy_arg, len);
}

void	ft_processor_unsign(t_flags *s_flags, va_list	*argptr, int *len)
{
	unsigned int	copy_arg;
	int				len_num;

	copy_arg = va_arg(*argptr, unsigned int);
	len_num = ft_len_unsign(copy_arg);
	if (s_flags->minus)
		ft_processor_unsign_1(s_flags, copy_arg, len_num, len);
	else
		ft_processor_unsign_2(s_flags, copy_arg, len_num, len);
}
