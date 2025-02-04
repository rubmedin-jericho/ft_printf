/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 12:05:20 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/30 12:05:39 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	a;
	int	nb;
	int	sign;

	sign = 1;
	a = 0;
	nb = 0;
	while (str[a] == ' ' || str[a] == '\n'
		|| str[a] == '\t' || str[a] == '\r'
		|| str[a] == '\f' || str[a] == '\v')
		a++;
	if (str[a] == '-')
	{
		sign = -1;
		a++;
	}
	else if (str[a] == '+')
		a++;
	while (str[a] >= 48 && str[a] <= 57)
	{
		nb = (nb * 10) + (str[a] - '0');
		a++;
	}
	return (nb * sign);
}
