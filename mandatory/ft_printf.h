/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 19:01:44 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 19:10:57 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

void	ft_processor(char *format, va_list argptr, int *len);
int		ft_printf(const char *format, ...);

void	ft_putchar(int c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_put_n(int n, int *len);
void	ft_put_u(unsigned int n, int *len);
void	ft_put_x(unsigned int n, int *len, char *format);
void	ft_put_p(unsigned long long int n, int *len, char *format);

#endif
