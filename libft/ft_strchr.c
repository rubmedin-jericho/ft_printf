/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 21:20:20 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/14 18:34:45 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	size_t			len;
	unsigned char	*str;
	unsigned char	cc;

	str = (unsigned char *)s;
	cc = (unsigned char)c;
	len = ft_strlen((char *)s);
	i = 0;
	while (i <= len)
	{
		if (cc == str[i])
		{
			str = &str[i];
			return ((char *)str);
		}
		i++;
	}
	if (str[i] && cc == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
