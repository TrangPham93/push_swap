/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:48:26 by trpham            #+#    #+#             */
/*   Updated: 2025/02/04 12:54:30 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	push_stack(t_node **stack_1, t_node **stack_2)
{
	t_node	*head;

	if (*stack_1 == NULL)
		return ;
	head = *stack_1;
	*stack_1 = (*stack_1)->next;
	if (*stack_1 != NULL)
		(*stack_1)->prev = NULL;
	head->next = (*stack_2);
	if (*stack_2 != NULL)
		(*stack_2)->prev = head;
	head->prev = NULL;
	*stack_2 = head;
}

int	pa(t_node **stack_a, char moves[], int i)
{
	push_stack(stack_a);
	moves[i] = '7';
	i++;
	return (i);
}

int	pb(t_node **stack_b, char moves[], int i)
{
	push_stack(stack_b);
	moves[i] = '8';
	i++;
	return (i);
}
