/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wbeck <wbeck@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:59:13 by wbeck             #+#    #+#             */
/*   Updated: 2021/12/27 19:00:17 by wbeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	type;
	int	width;
	int	precision;
	int	plus;
	int	minus;
	int	zero;
	int	space;
	int	hash;
}	t_flags;

size_t	ft_len_str(const char *s);
size_t	ft_len_int(int num);
size_t	ft_len_unsign(unsigned int num);
size_t	ft_len_pointer_hex(unsigned long long int num);

int		ft_atoi(char **format);
char	*ft_strchr(const char *s, int c);
char	*ft_check_base(t_flags *s_flags);
char	*ft_check_hash(t_flags *s_flags);

void	ft_init_flags(t_flags	*s_flags);
void	ft_parse(char *format, va_list *argptr, int *len);
int		ft_printf(const char *format, ...);

void	ft_check_flags(char **format, t_flags	*s_flags);
void	ft_check_width(char **format, t_flags	*s_flags, va_list *argptr);
void	ft_check_pres(char **format, t_flags	*s_flags, va_list *argptr);
void	ft_check_type(char **format, t_flags	*s_flags);
void	ft_processors(t_flags	*s_flags, va_list *argptr, int *len);

void	ft_putchar(char c, int *len);
void	ft_putstr(char *s, int *len, int size);
void	ft_putnbr(int n, int *len);
void	ft_putunsign(unsigned int n, int *len);
void	ft_putpointer(unsigned long long n, int *len, char *base);
void	ft_puthex(unsigned int n, int *len, char *base);

void	ft_processor_perc(t_flags *s_flags, int *len);
void	ft_processor_char(t_flags *s_flags, va_list	*argptr, int *len);
void	ft_processor_str(t_flags *s_flags, va_list	*argptr, int *len);
void	ft_processor_int(t_flags *s_flags, va_list	*argptr, int *len);
void	ft_processor_int_neg1(t_flags *s_flags, int copy_arg,
			int len_num, int *len);
void	ft_processor_int_neg2(t_flags *s_flags, int copy_arg,
			int len_num, int *len);			
void	ft_processor_int_zero1(t_flags *s_flags, int copy_arg,
			int len_num, int *len);
void	ft_processor_int_zero2(t_flags *s_flags, int copy_arg,
			int len_num, int *len);
void	ft_processor_unsign(t_flags *s_flags, va_list	*argptr, int *len);
void	ft_processor_pointer(t_flags *s_flags, va_list	*argptr, int *len);
void	ft_processor_hex(t_flags *s_flags, va_list	*argptr, int *len);
void	ft_processor_hex_1(t_flags *s_flags, unsigned int copy_hex,
			int len_hex, int *len);

#endif
