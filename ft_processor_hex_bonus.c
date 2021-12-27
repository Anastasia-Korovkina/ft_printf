/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:44:37 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 15:42:53 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_hex_4(t_flags *s_flags, char *hash,
int len_hex, int *len)
{
	int		fix_precision;

	fix_precision = s_flags->precision;
	if (s_flags->hash)
		len_hex += 2;
	if (s_flags->precision >= 0 && s_flags->precision >= len_hex)
	{
		s_flags->width -= (s_flags->precision);
		if (!s_flags->hash)
			ft_putchar(' ', len);
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
		if (s_flags->hash)
			ft_putstr(hash, len, 3);
	}
	else
	{
		if (s_flags->hash)
			ft_putstr(hash, len, 3);
		while ((s_flags->width)-- >= len_hex)
			ft_putchar(' ', len);
	}
	while ((fix_precision)-- >= len_hex)
		ft_putchar('0', len);
}

void	ft_processor_hex_2(t_flags *s_flags, char *hash, int len_hex, int *len)
{
	int	fix_precision;

	fix_precision = s_flags->precision;
	if (fix_precision >= s_flags->width && fix_precision != -1)
	{
		if (s_flags->hash)
			ft_putstr(hash, len, 3);
		while ((s_flags->precision)-- >= len_hex)
			ft_putchar('0', len);
	}
	else if (fix_precision < s_flags->width && fix_precision != -1)
		ft_processor_hex_4(s_flags, hash, len_hex, len);
	else
	{
		if (s_flags->zero)
			while ((s_flags->width)-- >= len_hex)
				ft_putchar('0', len);
		else
		{
			while ((s_flags->width)-- >= len_hex)
				ft_putchar(' ', len);
			if (s_flags->hash)
				ft_putstr(hash, len, 3);
		}
	}
}

void	ft_processor_hex_3(t_flags *s_flags, unsigned int copy_hex,
int len_hex, int *len)
{
	int		fix_precision;
	char	*base;

	fix_precision = s_flags->precision;
	base = ft_check_base(s_flags);
	if (s_flags->precision <= len_hex)
	{
		if (s_flags->precision == -1)
			(s_flags->width) -= 2;
		if (s_flags->precision == 1)
			(s_flags->width) += 1;
		if (s_flags->zero && s_flags->precision == -1)
			while ((s_flags->width)-- >= 0)
				ft_putchar('0', len);
		else
			while ((s_flags->width)-- > s_flags->precision)
				ft_putchar(' ', len);
	}
	else if (fix_precision > len_hex && fix_precision < s_flags->width)
		while ((s_flags->width)-- > s_flags->precision)
			ft_putchar(' ', len);
	while ((s_flags->precision)-- > 0)
		ft_putchar('0', len);
	if (fix_precision == -1)
		ft_puthex(copy_hex, len, base);
}

void	ft_processor_hex(t_flags *s_flags, va_list	*argptr, int *len)
{
	unsigned int	copy_hex;
	int				len_hex;
	char			*base;
	char			*hash;

	copy_hex = va_arg(*argptr, unsigned int);
	len_hex = ft_len_pointer_hex(copy_hex) + 1;
	base = ft_check_base(s_flags);
	hash = ft_check_hash(s_flags);
	if (copy_hex == 0 && s_flags->precision == 1)
		s_flags->width--;
	if (s_flags->minus)
		ft_processor_hex_1(s_flags, copy_hex, len_hex, len);
	else if (!s_flags->minus && copy_hex != 0)
	{
		ft_processor_hex_2(s_flags, hash, len_hex, len);
		ft_puthex(copy_hex, len, base);
	}
	else if (!s_flags->minus && copy_hex == 0)
		ft_processor_hex_3(s_flags, copy_hex, len_hex, len);
}
