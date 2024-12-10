#include "ft_printf.h"

static int	print_type(const int c, va_list argp)
{
	if (c == 'c')
		return (ft_putchar(va_arg(argp, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(argp, char *)));
	else if (c == 'p')
		return (ft_putaddr(va_arg(argp, void *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(argp, int)));
	else if (c == 'u')
		return (ft_putunbr(va_arg(argp, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(argp, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int	i;
	va_list argp;
	
	i = 0;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%' && !*(format + 1))
			break ;
		if (*format == '%')
		{
			format++;
			i += print_type(*format, argp);
		}
		else
			i += ft_putchar(*format);
		format++;
	}
	va_end(argp);
	return (i);
}
