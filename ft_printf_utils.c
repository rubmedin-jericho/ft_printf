/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:36:19 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/12 20:15:17 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_hexa_low(unsigned int n, int *i)
{
	char	*buff;

	buff = "0123456789abcdef";
	if (n >= 16)
		print_hexa_low(n / 16, i);
	ft_putchar_fd(buff[n % 16], 1, i);
}

void	print_hexa_upper(unsigned int n, int *i)
{
	char	*buff;

	buff = "0123456789ABCDEF";
	if (n >= 16)
		print_hexa_upper(n / 16, i);
	ft_putchar_fd(buff[n % 16], 1, i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
		i++;
	return (i);
}
