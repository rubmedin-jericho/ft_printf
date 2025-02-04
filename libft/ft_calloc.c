/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:25:08 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/04 21:14:25 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*ptr_str;
	size_t	i;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ptr_str = (char *)ptr;
	i = 0;
	while (i < (nmemb * size))
	{
		ptr_str[i] = '\0';
		i++;
	}
	return (ptr);
}
