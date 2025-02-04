/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:41:00 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/08 20:58:19 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*dst;

	if (dest == NULL || src == NULL || n == 0)
		return (dest);
	str = (char *)src;
	dst = (char *)dest;
	i = 0;
	while (i != n)
	{
		dst[i] = str[i];
		i++;
	}
	return (dst);
}
