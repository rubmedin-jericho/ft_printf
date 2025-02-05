#include "ft_printf.h"

void	print_hexa_low(unsigned long n)
{
	char *buff;

	buff = "0123456789abcdef";
	if (n >= 16)
		print_hexa_low(n / 16);
	ft_putchar_fd(buff[n % 16], 1);

}

void	print_hexa_upper(unsigned long n)
{
	char *buff;

	buff = "0123456789ABCDEF";
	if (n >= 16)
		print_hexa_upper(n / 16);
	ft_putchar_fd(buff[n % 16], 1);

}
