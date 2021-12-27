/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:13:25 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 14:14:19 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_init_flags(t_flags	*s_flags)
{
	s_flags->type = 0;
	s_flags->width = 0;
	s_flags->precision = -1;
	s_flags->minus = 0;
	s_flags->space = 0;
	s_flags->plus = 0;
	s_flags->zero = 0;
	s_flags->hash = 0;
}

void	ft_parse(char *format, va_list *argptr, int *len)
{
	t_flags	*s_flags;

	s_flags = malloc(sizeof(t_flags));
	if (!s_flags)
		return ;
	while (*format)
	{
		ft_init_flags(s_flags);
		if (*format == '%')
		{
			ft_check_flags(&format, s_flags);
			ft_check_width(&format, s_flags, argptr);
			ft_check_pres(&format, s_flags, argptr);
			ft_check_type(&format, s_flags);
			ft_processors(s_flags, argptr, len);
		}
		else
			ft_putchar(*(format), len);
		format++;
	}
	free(s_flags);
}

int	ft_printf(const char *format, ...)
{
	va_list	argptr;
	int		len;

	len = 0;
	va_start(argptr, format);
	ft_parse((char *)format, &argptr, &len);
	va_end(argptr);
	return (len);
}


// #include <stdio.h>

// int main()
// {
// 	ft_printf("%p\n", (void *)0);
// 	printf("%p", (void *)0);
// }