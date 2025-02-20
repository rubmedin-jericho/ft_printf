/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 18:25:48 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/20 00:05:18 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	switch_function(char c, va_list arg, int *i)
{
	if (c == 'c')
		ft_putchar_fd(va_arg(arg, int), 1, i);
	else if (c == 's')
		ft_putstr_fd(va_arg(arg, char *), 1, i);
	else if (c == 'p')
		ptrnbr_base(va_arg(arg, unsigned long), 16, i);
	else if (c == 'd' || c == 'i')
		ft_putnbr_fd(va_arg(arg, long), 1, i);
	else if (c == 'u')
		put_nbr(va_arg(arg, unsigned long), i);
	else if (c == 'x')
		print_hexa_low(va_arg(arg, long), i);
	else if (c == 'X')
		print_hexa_upper(va_arg(arg, long), i);
	else if (c == '%')
		ft_putchar_fd('%', 1, i);
	else
		*i = -1;
}

int	ft_printf(char const *s, ...)
{
	int		count;
	va_list	v_args;
	int		i;

	if (!s)
		return (-1);
	va_start(v_args, s);
	count = 0;
	i = 0;
	while (s[i] && count != -1)
	{
		if (s[i] == '%')
			switch_function(s[++i], v_args, &count);
		else
			ft_putchar_fd(s[i], 1, &count);
		i++;
	}
	va_end(v_args);
	return (count);
}
