#include "ft_printf.h"

int	ft_puthex(unsigned long n, char c)
{
	int	i;
	char *set;
	char *set1;
	
	i = 0;
	set = "0123456789abcdef";
	set1 = "0123456789ABCDEF";
	
	if (n > 15)
		i += ft_puthex(n / 16, c);
	if (c == 'x')
		i += ft_putchar(set[n % 16]);
	else
		i += ft_putchar(set1[n % 16]);
	return (i);
}
/*
int main()
{
	unsigned int i = 1456;
	char c = 'x';
	int char_print = ft_puthex(i, c);
	printf("\n%d\n", char_print);
	return 0;
}
*/
