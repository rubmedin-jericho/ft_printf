/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:08:31 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/14 18:52:25 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*str;
	unsigned char	cc;
	size_t			len;
	size_t			i;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	len = ft_strlen((char *)str);
	i = 0;
	while (len > i)
	{
		if (str[len] == cc)
			return ((char *)&str[len]);
		len--;
	}
	if (str[len] == cc && cc == '\0')
		return ((char *)&str[len]);
	else if (str[len] == cc)
		return ((char *)&str[len]);
	return (NULL);
}
