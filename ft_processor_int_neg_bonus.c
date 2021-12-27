/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_int_neg.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:17:06 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 15:18:10 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_int_neg1(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->precision >= len_num)
	{
		ft_putchar('-', len);
		while ((s_flags->precision)-- >= len_num)
			ft_putchar('0', len);
		ft_putnbr(-copy_arg, len);
		while ((s_flags->width)-- > fix_precision + 1)
			ft_putchar(' ', len);
	}
	else
	{
		if (copy_arg == -2147483648)
			ft_putchar('-', len);
		ft_putnbr(copy_arg, len);
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
	}
}

void	ft_processor_int_neg2(t_flags *s_flags, int copy_arg,
int len_num, int *len)
{
	if (s_flags->precision >= len_num)
	{
		while ((s_flags->width)-- > s_flags->precision + 1)
			ft_putchar(' ', len);
		ft_putchar('-', len);
		while ((s_flags->precision)-- >= len_num)
			ft_putchar('0', len);
		ft_putnbr(-copy_arg, len);
	}
	else if (s_flags->precision == -1 && s_flags->zero)
	{	
		ft_putchar('-', len);
		while ((s_flags->width)-- > len_num)
			ft_putchar('0', len);
		ft_putnbr(-copy_arg, len);
	}
	else
	{
		while ((s_flags->width)-- > len_num)
			ft_putchar(' ', len);
		if (copy_arg == -2147483648)
			ft_putchar('-', len);
		ft_putnbr(copy_arg, len);
	}
}
