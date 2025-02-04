/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:31:42 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/31 16:11:52 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	intlent(int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr > 1)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

static int	ft_conversor(int j)
{
	int	k;

	k = intlent(j);
	while (k > 0)
	{
		j = j % 10;
		k--;
	}
	return (j * -1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		j;

	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	j = s1[i] - s2[i];
	if (s1[i] < '\0' || s2[i] < '\0')
		j = ft_conversor(j);
	if (j < 0)
		return (-1);
	else if (j > 0)
		return (1);
	return (s1[i] - s2[i]);
}
