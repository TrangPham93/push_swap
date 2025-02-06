/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:21:58 by trpham            #+#    #+#             */
/*   Updated: 2025/02/06 11:31:52 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	sort_stack_of_two(t_node **stack_a, char moves[], int i)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		i = sa(stack_a, moves, i);
	return (i);	
}

int	sort_stack_of_three(t_node	**stack_a, char moves[], int i)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;

	if (a < c && c < b)
	{
		i = rra(stack_a, moves, i);
		i = sa(stack_a, moves, i);
	}
	else if (b < a && a < c)
		i = sa(stack_a, moves, i);
	else if (c < a && a < b)
		i = rra(stack_a, moves, i);
	else if (b < c && c < a)
		i = ra(stack_a, moves, i);
	else if (c < b && b < a)
	{
		i = sa(stack_a, moves, i);
		i = rra(stack_a, moves, i);
	}
	return (i);
}
int	sort_stack_of_four(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	t_node	*min_node;

	min_node = find_min_node(*stack_a);
	i = move_to_top_a(stack_a, min_node, moves, i);
	i = pb(stack_a, stack_b, moves, i);
	i = sort_stack_of_three(stack_a, moves, i);
	i = pa(stack_b, stack_a, moves, i);
	return (i);
}

int	sort_stack_of_five(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	t_node	*min_node;
	int	count;

	count = 0;
	while (count < 2)
	{
		min_node = find_min_node(*stack_a);
		i = move_to_top_a(stack_a, min_node, moves, i);
		i = pb(stack_a, stack_b, moves, i);
		count++;
	}
	i = sort_stack_of_three(stack_a, moves, i);
	while (count)
	{
		i = pa(stack_b, stack_a, moves, i);
		count--;
	}
	return (i);
}
