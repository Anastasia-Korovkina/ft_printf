#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
#include <stdio.h>


void	ft_processor(char *format, va_list *argptr, int *len);
int		ft_printf(const char *format, ...);

void    ft_putchar(int c, int *len);
void	ft_putstr(char *s, int *len);
void	ft_put_n(int n, int *len);
void	ft_put_u(unsigned int n, int *len);
void	ft_put_x(unsigned int n, int *len, char *format);
void	ft_put_p(unsigned long long int n, int *len, char *format);

#endif
