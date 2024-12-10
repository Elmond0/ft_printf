#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int i;
	long  nb;
	
	i = 0;
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		i += ft_putchar('-');
	}
	if (nb > 9)
		i += ft_putnbr(nb / 10);
	i += ft_putchar(nb % 10 + '0');
	return (i);	
}
