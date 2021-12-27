/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_smth.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:54 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 14:13:55 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_putstr(char *s, int *len, int size)
{
	int	i;

	i = 0;
	while (s[i] && i < size)
	{
		ft_putchar(s[i], len);
		i++;
	}
}

void	ft_putnbr(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("2147483648", len, 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', len);
	}
	if (n > 9)
		ft_putnbr(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_putunsign(unsigned int n, int *len)
{
	if (n > 9)
		ft_putunsign(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_puthex(unsigned int n, int *len, char *base)
{
	if (n >= 16)
		ft_puthex(n / 16, len, base);
	ft_putchar(base[n % 16], len);
}
