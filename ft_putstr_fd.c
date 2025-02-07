/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:48 by rubmedin          #+#    #+#             */
/*   Updated: 2025/01/04 21:16:55 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if(write(fd, &s[i], 1))
			*coutn = -1;
		i++;
		if(*coutn != -1)
			*count += 1;
	}
}
