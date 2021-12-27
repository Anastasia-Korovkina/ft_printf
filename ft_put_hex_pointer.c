/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hex_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:01:00 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 20:12:38 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_base(char *format)
{
	if (*format == 'x' || *format == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

void	ft_put_x(unsigned int n, int *len, char *format)
{
	char	*base;

	base = ft_base(format);
	if (n >= 16)
		ft_put_x(n / 16, len, format);
	ft_putchar(base[n % 16], len);
}

void	ft_put_p(unsigned long long int n, int *len, char *format)
{
	char	*base;

	base = ft_base(format);
	if (n >= 16)
		ft_put_p(n / 16, len, format);
	ft_putchar(base[n % 16], len);
}
