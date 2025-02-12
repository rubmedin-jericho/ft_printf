/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 11:54:50 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/12 20:14:52 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	extra_case(int n, int *i)
{
	if (n > INT_MAX)
		ft_putstr_fd("-1", 1, i);
	if (n < INT_MIN)
		ft_putchar_fd('0', 1, i);
}

void	ft_putnbr_fd(int n, int fd, int *i)
{
	if (n < -2147483648 || n > 2147483647)
		extra_case(n, i);
	else if (n == -2147483648)
		ft_putstr_fd("-2147483648", 1, i);
	else if (n == 2147483647)
		ft_putstr_fd("2147483647", 1, i);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd, i);
		n = -n;
	}
	if (n >= 10 && n < INT_MAX)
	{
		ft_putnbr_fd(n / 10, fd, i);
		ft_putchar_fd(n % 10 + '0', fd, i);
	}
	else if (n < 10 && n > INT_MIN)
		ft_putchar_fd(n % 10 + '0', fd, i);
}
