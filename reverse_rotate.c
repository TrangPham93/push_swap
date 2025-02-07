/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:41:43 by trpham            #+#    #+#             */
/*   Updated: 2025/02/07 14:29:54 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_node **lst)
{
	t_node	*second_to_tail;
	t_node	*tail;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tail = *lst;
	while (tail->next != NULL)
	{
		second_to_tail = tail;
		tail = tail->next;
	}
	tail->next = *lst;
	tail->prev = NULL;
	(*lst)->prev = tail;
	second_to_tail->next = NULL;
	*lst = tail;
}

int	rra(t_node **stack_a, char moves[], int i)
{
	reverse_rotate(stack_a);
	moves[i] = '5';
	i++;
	return (i);
}

int	rrb(t_node **stack_b, char moves[], int i)
{
	reverse_rotate(stack_b);
	moves[i] = '6';
	i++;
	return (i);
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
