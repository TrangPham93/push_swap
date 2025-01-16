/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:56:47 by trpham            #+#    #+#             */
/*   Updated: 2025/01/16 18:18:30 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	count;

	if (!s)
		return (ft_putstr_fd("(null)", fd));
	count = 0;
	while (s[count])
	{
		ft_putchar_printf(s[count], fd);
		count++;
	}
	return (count);
}
