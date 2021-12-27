/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_and_proc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:12:53 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/08 17:51:50 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_check_flags(char **format, t_flags	*s_flags)
{
	while (ft_strchr("+-0 #", *(++(*format))))
	{
		if (**format == '+')
			s_flags->plus = 1;
		if (**format == '-')
			s_flags->minus = 1;
		if (**format == '0')
			s_flags->zero = 1;
		if (**format == ' ')
			s_flags->space = 1;
		if (**format == '#')
			s_flags->hash = 1;
	}
}

void	ft_check_width(char **format, t_flags	*s_flags, va_list *argptr)
{
	if (**format == '*')
	{
		s_flags->width = va_arg(*argptr, int);
		if (s_flags->width < 0)
		{
			s_flags->width *= -1;
			s_flags->minus = 1;
		}
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
		s_flags->width = ft_atoi(format);
}

void	ft_check_pres(char **format, t_flags	*s_flags, va_list *argptr)
{
	if (**format == '.')
	{
		s_flags->precision = 0;
		(*format)++;
		if (**format == '*')
		{
			s_flags->precision = va_arg(*argptr, int);
			if (s_flags->precision < -1)
				s_flags->precision = -1;
			(*format)++;
		}
		else if (**format >= '0' && **format <= '9')
			s_flags->precision = ft_atoi(format);
	}
}

void	ft_check_type(char **format, t_flags	*s_flags)
{
	if (ft_strchr("cspdiuxX%", **format))
		s_flags->type = **format;
}

void	ft_processors(t_flags	*s_flags, va_list *argptr, int *len)
{
	if (s_flags->type == '%')
		ft_processor_perc(s_flags, len);
	if (s_flags->type == 'c')
		ft_processor_char(s_flags, argptr, len);
	if (s_flags->type == 's')
		ft_processor_str(s_flags, argptr, len);
	if (s_flags->type == 'd' || s_flags->type == 'i')
		ft_processor_int(s_flags, argptr, len);
	if (s_flags->type == 'u')
		ft_processor_unsign(s_flags, argptr, len);
	if (s_flags->type == 'p')
	{
		if (argptr == NULL)
		{
			ft_putstr("0x0", len, 4);
			return ;
		}
		else
			ft_processor_pointer(s_flags, argptr, len);
	}
	if (s_flags->type == 'x' || s_flags->type == 'X')
		ft_processor_hex(s_flags, argptr, len);
}
