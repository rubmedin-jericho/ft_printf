/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rubmedin <rubmedin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 16:20:48 by rubmedin          #+#    #+#             */
/*   Updated: 2025/02/11 16:34:03 by rubmedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int *count)
{
	int	i;

	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	i = 0;
	while (s[i] && *count != -1)
	{
		ft_putchar_fd(s[i], fd, count);
		i++;
	}
}
