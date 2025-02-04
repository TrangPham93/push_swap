/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:09:00 by trpham            #+#    #+#             */
/*   Updated: 2025/02/04 14:42:24 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	swap_stack(t_node **lst)
{
	t_node	*node1;
	t_node	*node2;

	node1 = NULL;
	node2 = NULL;
	if (lst == NULL || (*lst)->next == NULL)
		return ;
	node1 = *lst;
	node2 = (*lst)->next;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = NULL;
	*lst = node2;
}

int	sa(t_node **stack_a, char moves[], int i)
{
	swap_stack(stack_a);
	moves[i] = '1';
	i++;
	return (i);
}

int	sb(t_node **stack_b, char moves[], int i)
{
	swap_stack(stack_b);
	moves[i] = '2';
	i++;
	return (i);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
}
