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

void	ptrnbr_base(unsigned long n, int base, int *i)
{
	char *buff;

	if((void *)n == NULL)
	{
		if(write(1, "(nil)", 6));
			*i = -1;
		if(*i != -1)
			*i += 1;
		return ;
	}
	buff = "0123456789abcdef";
	if (n >= (unsigned long)base)
		ptrnbr_base((n / base), base, &i);
	else if(n < (unsigned long)base && (void *)n != NULL)
	{
		if(write(1, "0x", 2))
			*i = -1;
		if(*i != -1)
			*i += 1;
	}
	ft_putchar_fd(buff[n % base], 1, &i);
}

void	put_nbr(unsigned int n, int *i)
{
	if (n >= 10)
		put_nbr(n / 10, &i);
	ft_putchar_fd((n % 10) + '0', 1, &i);
	if(*i != -1)
		*i += 1;
}

void	switch_function(char c, va_list arg, int *i)
{
	if(c == 'c')
		ft_putchar_fd(va_arg(arg, int), 1, &i);	
	else if( c == 's')
		ft_putstr_fd(va_arg(arg, char *), 1, &i);
	else if(c == 'p')
		ptrnbr_base(va_arg(arg, unsigned long), 16, &i);
	else if (c == 'd' || c == 'i')	
		ft_putnbr_fd(va_arg(arg, int), 1, &i);
	else if (c == 'u')
		put_nbr(va_arg(arg, unsigned long), &i);	
	else if (c == 'x')
		print_hexa_low(va_arg(arg, unsigned long), &i);
	else if (c == 'X')
		print_hexa_upper(va_arg(arg, unsigned long), &i);
	else if (c == '%')
	{
		if(write(1, "%", 1))
			*i = -1;
		if(*i != -1)
			*i += 1
	}
}

int ft_printf(char const *s, ...)
{	
	char *word;
	int	i;
	va_list v_args;

	if(!s)
		return (-1);
	va_start(v_args, s);
	word = (char *)s;
	i = 0;
	while(*s)
	{
		if(*s != '%')
			ft_putchar_fd(*s, 1, &i);
		else if(*s == '%' && (ft_isalpha((*s + 1)) || (*s + 1) == '%'))
		{
			switch_function((char)(*s + 1), v_args);	
			s++;
		}
		s++;
	}
	va_end(v_args);
	return(i);
}
//
//int	main()
//{
//	char *str = "hola";
//	
//	ft_printf("caracter: %c\nstring: %s\nmemory address: %p\ndecimal: %d\ninteger: %i\ninteger sin signo: %u\nhexadecimal minuscula: %x\nhexa mayus %X\nporcentaje: %%\n", 'R', "hola", str, 234, 1234567, -1235, 10, 10);
//	return (0);
//}
