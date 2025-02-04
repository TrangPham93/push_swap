/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:21:58 by trpham            #+#    #+#             */
/*   Updated: 2025/02/04 14:41:02 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	sort_stack_of_two(t_node **stack_a, char moves[], int i)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		sa(stack_a, moves, i);
}

void	sort_stack_of_three(t_node	**stack_a, char moves[], int i)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;

	if (a < c && c < b)
	{
		rra(stack_a, moves, i);
		sa(stack_a, moves, i);
	}
	else if (b < a && a < c)
		sa(stack_a, moves, i);
	else if (c < a && a < b)
		rra(stack_a, moves, i);
	else if (b < c && c < a)
		ra(stack_a, moves, i);
	else if (c < b && b < a)
	{
		sa(stack_a, moves, i);
		rra(stack_a, moves, i);
	}
}
void sort_stack_of_four(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	t_node	*min_node;

	min_node = find_min_node(*stack_a);
	move_to_top_a(stack_a, min_node, moves, i);
	pb(stack_a, stack_a, moves, i);
	// print_list(*stack_a);
	// print_list(*stack_b);
	sort_stack_of_three(stack_a, moves, i);
	pa(stack_b, stack_a, moves, i);
}

void sort_stack_of_five(t_node **stack_a, t_node **stack_b, char moves[], int i)
{
	t_node	*min_node;
	int	count;

	count = 0;
	while (count++ < 2)
	{
		min_node = find_min_node(*stack_a);
		move_to_top_a(stack_a, min_node, moves, i);
		pb(stack_a, stack_b, moves, i);
	}
	sort_stack_of_three(stack_a, moves, i);
	while (count--)
		pa(stack_b, stack_a, moves, i);
}
