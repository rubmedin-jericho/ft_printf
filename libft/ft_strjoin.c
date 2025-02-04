/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 00:14:54 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/30 11:57:04 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
	{
		return (NULL);
	}
	str = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (!str)
		return (NULL);
	if (!s1)
		ft_strlcpy(str, s2, ft_strlen(s2));
	else if (!s2)
		ft_strlcpy(str, s1, ft_strlen(s1));
	else
	{
		ft_strlcpy(str, s1, (ft_strlen(s1) + 1));
		ft_strlcat(str, s2, ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	}
	str[ft_strlen(s1) + ft_strlen(s2) + 1] = '\0';
	return (str);
}
