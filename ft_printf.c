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

void	putnbr_base(int n, int base)
{
	
	char *buff;

	buff = "0123456789abcdf";
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
	}
	if (n >= base)
		putnbr_base((n / base), base);
	ft_putchar_fd((char)buff[n % base], 1);
}

//void	switch_function(char c, char *arg)
//{
//	(void)arg;
//	if(c == 'c')
//		ft_putchar_fd(arg[0], 1);	
//	else if( c == 's')
//		ft_putstr_fd(arg, 1);
//	else if(c == 'p')
//		putnbr_base(&arg, 16);
//	else if (c == 'd')
////		funtion
//	else if (c == 'i')	
//		ft_putnbr_fd(ft_atoi(arg), 1);
//	else if (c == 'u')
//		printf(" u ");
//	else if (c == 'x')
//		printf(" x ");
//	else if (c == 'X')
//		printf(" X ");
//	else if (c == '%')
//		printf(" XD ");
//}
//
//int ft_printf(char const *s, ...)
//{	
//	char *str;
//	char *word;
//	int	i;
//
//	va_list v_args;
//
//	va_start(v_args, s);
//	word = (char *)s;
//	i = 0;
//	while(s[i])
//	{
//		if(s[i] != '%')
//			ft_putchar_fd(s[i], 1);
//		else if(s[i] == '%' && ft_isalpha(s[i + 1]))
//		{
//			str = (char *)va_arg(v_args, char const *);
//			switch_function(word[i + 1], str);	
//			i++;
//		}
//		i++;
//	}
//	va_end(v_args);
//	return(0);
//}

int	main()
{
	//ft_printf("este %s no sale", "hola");
	putnbr_base(15, 16);
	return (0);
}
