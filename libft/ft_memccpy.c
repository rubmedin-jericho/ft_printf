/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:39:47 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/04 21:15:25 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_print(int c)
{
	if (c <= 31 || c > 127)
		return (1);
	return (0);
}

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*str;
	char	*buff;
	size_t	i;

	str = (char *)src;
	buff = (char *)dest;
	if (str[0] == '\0' || n == 0 || (is_print((char)c)) == 1 || str == NULL
		|| dest == NULL)
		return (NULL);
	i = 0;
	while (i < n && str[i] && str[i] != c)
	{
		buff[i] = str[i];
		i++;
	}
	if (str[i] == c && i != n)
	{
		buff[i] = str[i];
		i++;
	}
	buff[i] = '\0';
	return (dest);
}
