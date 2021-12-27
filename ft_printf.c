#include "ft_printf.h"

void ft_processor(char *format, va_list *argptr, int *len)
{
	// char	*copy_arg;

    while(*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '%')
                ft_putchar('%', len);
            if (*format == 'c')
                ft_putchar(va_arg(*argptr, int), len);
            if (*format == 's')
            {
                // copy_arg = ;
                // if (copy_arg == NULL)
                //     copy_arg = "(null)";
                ft_putstr(va_arg(*argptr, char *), len);
            }
            if (*format == 'd' || *format == 'i')
                ft_put_n(va_arg(*argptr, int), len);
            if (*format == 'u')
                ft_put_u(va_arg(*argptr, unsigned int), len);
            if (*format == 'x' || *format == 'X')
                ft_put_x(va_arg(*argptr, unsigned int), len, format);
            if (*format == 'p')
            {
                ft_putstr("0x", len);
                ft_put_p(va_arg(*argptr, unsigned long long int), len, format);
            }
        }
        else
            ft_putchar(*format, len);
        format++;
    }
}

int ft_printf(const char *format, ...)
{
    va_list	argptr;
	int		len;

    va_start(argptr, format);
    ft_processor((char *)format, &argptr, &len);
    va_end(argptr);
    return (len);
}


// #include <stdio.h>
// int main()
// {
//     ft_printf("%X\n", 122);
//     printf("%X\n", 122);
//     return (0);
// }