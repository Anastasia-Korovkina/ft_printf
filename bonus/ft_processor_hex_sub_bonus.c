/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_hex_sub.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 15:42:44 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 15:43:32 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_hex_5(t_flags *s_flags, unsigned int copy_hex,
int len_hex, int *len)
{
	int		fix_precision;
	char	*base;

	fix_precision = s_flags->precision;
	base = ft_check_base(s_flags);
	if (fix_precision >= s_flags->width || fix_precision >= len_hex)
	{
		while ((s_flags->precision)-- >= len_hex)
			ft_putchar('0', len);
		if (copy_hex != 0)
			ft_puthex(copy_hex, len, base);
		while ((s_flags->width)-- > fix_precision)
			ft_putchar(' ', len);
	}
	else
	{
		if (copy_hex != 0)
			ft_puthex(copy_hex, len, base);
		while ((s_flags->width)-- >= len_hex)
			ft_putchar(' ', len);
	}
}

void	ft_processor_hex_1(t_flags *s_flags, unsigned int copy_hex,
int len_hex, int *len)
{
	char	*base;
	char	*hash;

	hash = ft_check_hash(s_flags);
	base = ft_check_base(s_flags);
	if (copy_hex == 0 && s_flags->precision == -1)
	{
		(s_flags->width)--;
		ft_puthex(copy_hex, len, base);
	}
	if (copy_hex == 0 && s_flags->precision == 1)
		(s_flags->width)++;
	if (s_flags->hash)
		ft_putstr(hash, len, 3);
	ft_processor_hex_5(s_flags, copy_hex, len_hex, len);
}
