/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:56:03 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 20:22:39 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_processor(char *format, va_list argptr, int *len)
{
	if (*format == '%')
		ft_putchar('%', len);
	if (*format == 'c')
		ft_putchar(va_arg(argptr, int), len);
	if (*format == 's')
		ft_putstr(va_arg(argptr, char *), len);
	if (*format == 'd' || *format == 'i')
		ft_put_n(va_arg(argptr, int), len);
	if (*format == 'u')
		ft_put_u(va_arg(argptr, unsigned int), len);
	if (*format == 'x' || *format == 'X')
		ft_put_x(va_arg(argptr, unsigned int), len, format);
	if (*format == 'p')
	{
		ft_putstr("0x", len);
		ft_put_p(va_arg(argptr, unsigned long long int), len, format);
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		len;

	va_start(argptr, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_processor((char *)format, argptr, &len);
		}
		else
			ft_putchar(*format, &len);
		format++;
	}
	va_end(argptr);
	return (len);
}
