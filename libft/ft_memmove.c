/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:24:49 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/31 14:35:30 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*src_tmp;
	char	*dest_tmp;
	size_t	lenght;
	size_t	i;

	src_tmp = (char *)src;
	dest_tmp = (char *)dest;
	lenght = n;
	i = 0;
	if (dest_tmp > src_tmp)
	{
		while (lenght-- > 0)
			dest_tmp[lenght] = src_tmp[lenght];
	}
	else
	{
		while (i < n)
		{
			dest_tmp[i] = src_tmp[i];
			i++;
		}
	}
	return (dest);
}
