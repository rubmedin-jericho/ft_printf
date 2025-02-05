/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:25:48 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/31 18:25:52 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> 

void	ptrnbr_base(unsigned long n, int base)
{
	char *buff;

	if((void *)n == NULL)
	{
		write(1, "(nil)", 6);
		return ;
	}
	buff = "0123456789abcdef";
	if (n >= (unsigned long)base)
		ptrnbr_base((n / base), base);
	else if(n < (unsigned long)base && (void *)n != NULL)
		write(1, "0x", 2);
	ft_putchar_fd(buff[n % base], 1);
}

//void	putnbr_base(int n, int base)
//{
//	char *buff;
//
//	buff = "0123456789abcdef";
//	if((int)n == -2147483648)
//		write(1, "-2147483648", 10);
//	if (n < 0)
//	{
//		ft_putchar_fd('-', 1);
//		n = -n;
//	}
//	if (n >= (unsigned long)base)
//		putnbr_base((n / base), base);
//	ft_putchar_fd(buff[n % base], 1);
//}

void	ft_atoi_sinsing(const char *str)
{
	int		a;
	size_t	nb;

	a = 0;
	nb = 0;
	while (str[a] == ' ' || str[a] == '\n'
		|| str[a] == '\t' || str[a] == '\r'
		|| str[a] == '\f' || str[a] == '\v')
		a++;
	if (str[a] == '+')
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		nb = (nb * 10) + (str[a] - '0');
		a++;
	}
	ft_putnbr_fd(nb, 1);
}

void	put_nbr(unsigned long n)
{
	if (n >= 10)
		put_nbr(n / 10);
	ft_putchar_fd((int)n % 10 + '0', 1);
}

void	switch_function(char c, char *arg)
{
	if(c == 'c')
		ft_putchar_fd(arg[0], 1);	
	else if( c == 's')
		ft_putstr_fd(arg, 1);
	else if(c == 'p')
		ptrnbr_base((unsigned long)arg, 16);
	else if (c == 'd')	
		ft_putnbr_fd(ft_atoi(arg), 1);
	else if (c == 'i')	
		ft_putnbr_fd(ft_atoi(arg), 1);
	else if (c == 'u')
		put_nbr(ft_atoi(arg));	
//	else if (c == 'x')
//		printf(" x ");
//	else if (c == 'X')
//		printf(" X ");
//	else if (c == '%')
//		printf(" XD ");
}

int ft_printf(char const *s, ...)
{	
	char *str;
	char *word;
	int	i;

	va_list v_args;

	va_start(v_args, s);
	word = (char *)s;
	i = 0;
	while(s[i])
	{
		if(s[i] != '%')
			ft_putchar_fd(s[i], 1);
		else if(s[i] == '%' && ft_isalpha(s[i + 1]))
		{
			str = (char *)va_arg(v_args, char const *);
			switch_function(word[i + 1], str);	
			i++;
		}
		i++;
	}
	va_end(v_args);
	return(0);
}

int	main()
{
	char *str = "hola";
	
	ft_printf("caracter: %c\nstring: %s\nmemory address: %p\ndecimal: %d\ninteger: %i\ninteger sin signo: %u\n", "R", "hola", str, "234.1", "1234567", "-1235");
	printf("num sinsig original: %u\n", -1235);
	return (0);
}
