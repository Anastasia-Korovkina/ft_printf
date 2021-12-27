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