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

void	prueba_function(char c, char *arg)
{
	(void)arg;
	printf("%c\n", c);
	if(c == 'c')
		printf("c\n");
	else if( c == 's')
		printf("sS\n");	
	else if(c == 'p')
		printf("p\n");
	else if (c == 'd')
		printf("d\n");
	else if (c == 'i')
		printf("i\n");
	else if (c == 'u')
		printf("u\n");
	else if (c == 'x')
		printf("x\n");
	else if (c == 'X')
		printf("X\n");
	else if (c == '%')
		printf("XD\n");
}

#include <stdio.h> 

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
		//printf("str: %c\n", s[i]);
		if(s[i] == '%' && ft_isalpha(s[i + 1]))
		{
			//printf("ENTRA\n");
			str = (char *)va_arg(v_args, char const *);
			prueba_function(word[i + 1], str);	
		}
		else
			//ft_putchar_fd();
		i++;
	}
	va_end(v_args);
	return(0);
}

int	main()
{
	ft_printf("este%s no %csale", "hola", "adios");
	return (0);
}
