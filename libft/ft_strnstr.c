/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 21:12:05 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/30 11:57:17 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_lit;

	if (!little || !*little || !big)
		return ((char *)big);
	i = 0;
	len_lit = ft_strlen(little);
	while (i + len_lit <= len && big[i] && ft_strncmp(&big[i], little, len_lit))
		i++;
	if (!ft_strncmp(&big[i], little, len_lit) && i + len_lit <= len)
		return ((char *)&big[i]);
	return (NULL);
}
