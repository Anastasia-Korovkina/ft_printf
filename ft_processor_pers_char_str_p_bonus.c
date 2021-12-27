/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_processor_pers_char_str_p.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:47 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 14:13:48 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_processor_perc(t_flags *s_flags, int *len)
{
	if (s_flags->minus)
	{
		ft_putchar('%', len);
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
	}
	else if (s_flags->zero)
	{	
		while ((s_flags->width)-- > 1)
			ft_putchar('0', len);
		ft_putchar('%', len);
	}
	else
	{
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
		ft_putchar('%', len);
	}
}

void	ft_processor_char(t_flags *s_flags, va_list	*argptr, int *len)
{
	if (s_flags->minus)
	{
		ft_putchar(va_arg(*argptr, int), len);
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
	}
	else
	{
		while ((s_flags->width)-- > 1)
			ft_putchar(' ', len);
		ft_putchar(va_arg(*argptr, int), len);
	}
}

void	ft_processor_str(t_flags *s_flags, va_list	*argptr, int *len)
{
	char	*copy_arg;
	int		size;

	copy_arg = va_arg(*argptr, char *);
	if (copy_arg == NULL)
		copy_arg = "(null)";
	size = ft_len_str(copy_arg);
	if (s_flags->precision >= 0 && s_flags->precision < size)
		size = s_flags->precision;
	if (s_flags->minus)
	{
		ft_putstr(copy_arg, len, size);
		while ((s_flags->width)-- > size)
			ft_putchar(' ', len);
	}
	else
	{
		while ((s_flags->width)-- > size)
			ft_putchar(' ', len);
		if (!copy_arg)
			ft_putstr("(null)", len, ft_len_str("(null)"));
		else
			ft_putstr(copy_arg, len, size);
	}
}

void	ft_putpointer(unsigned long long int n, int *len, char *base)
{
	if (n >= 16)
		ft_putpointer(n / 16, len, base);
	ft_putchar(base[n % 16], len);
}

void	ft_processor_pointer(t_flags *s_flags, va_list	*argptr, int *len)
{
	unsigned long long int	copy_p;
	int						len_p;
	char					*base;

	base = ft_check_base(s_flags);
	copy_p = va_arg(*argptr, unsigned long long int);
	len_p = ft_len_pointer_hex(copy_p) + 2;
	if (copy_p == 0)
		s_flags->width--;
	if (s_flags->minus)
	{
		ft_putstr("0x", len, 3);
		ft_putpointer(copy_p, len, base);
		while ((s_flags->width)-- > len_p)
			ft_putchar(' ', len);
	}
	else
	{
		while ((s_flags->width)-- > len_p)
			ft_putchar(' ', len);
		ft_putstr("0x", len, 3);
		ft_putpointer(copy_p, len, base);
	}
}
