/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lengths.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:17 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 14:13:18 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

size_t	ft_len_str(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_len_int(int num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

size_t	ft_len_unsign(unsigned int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

size_t	ft_len_pointer_hex(unsigned long long int num)
{
	int	len;

	len = 0;
	while (num)
	{
		num /= 16;
		len++;
	}
	return (len);
}
