#include "ft_printf.h"

void    ft_putchar(int c, int *len)
{
    write(1, &c, 1);
    (*len)++;
}

void	ft_putstr(char *s, int *len)
{
	while (*s)
		ft_putchar(*s++, len);
}

void	ft_put_n(int n, int *len)
{
	if (n == -2147483648)
	{
		ft_putstr("2147483648", len);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-', len);
	}
	if (n > 9)
		ft_put_n(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}

void	ft_put_u(unsigned int n, int *len)
{
	if (n > 9)
		ft_put_u(n / 10, len);
	ft_putchar(n % 10 + '0', len);
}
