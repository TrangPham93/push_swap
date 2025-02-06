/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:53:48 by trpham            #+#    #+#             */
/*   Updated: 2025/02/06 17:07:11 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	ft_is_valid_number(char	*str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	is_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (-1);
	temp = stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (-1);
	}
	return (0);
}
