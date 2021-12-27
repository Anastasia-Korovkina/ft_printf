/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:07 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 14:13:09 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_atoi(char **format)
{
	int	res;

	res = 0;
	while (**format >= '0' && **format <= '9')
	{
		res = res * 10 + **format - '0';
		(*format)++;
	}
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_len_str(s);
	while (s[i] && len > 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		len--;
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_check_base(t_flags *s_flags)
{
	if (s_flags->type == 'x' || s_flags->type == 'p')
		return ("0123456789abcdef");
	else
		return ("0123456789ABCDEF");
}

char	*ft_check_hash(t_flags *s_flags)
{
	if (s_flags->type == 'x')
		return ("0x");
	else
		return ("0X");
}
