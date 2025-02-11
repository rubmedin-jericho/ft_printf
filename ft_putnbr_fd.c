/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:54:50 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/11 16:33:50 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(int n, int fd, int *i)
{
	if (n == -2147483648)
	{
		if (write(fd, "-2", 2))
			*i = -1;
		if (*i != -1)
			*i += 11;
		n = 147483648;
	}
	if (n < 0)
	{
		ft_putchar_fd('-', fd, i);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd, i);
		ft_putchar_fd(n % 10 + '0', fd, i);
	}
	if (n < 10)
	{
		ft_putchar_fd(n % 10 + '0', fd, i);
	}
}
