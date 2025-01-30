/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:21:58 by trpham            #+#    #+#             */
/*   Updated: 2025/01/30 17:32:53 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	sort_stack_of_two(t_node **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap_stack(stack_a, 'a');
}

void	sort_stack_of_three(t_node	**stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;

	if (a < c && c < b)
	{
		reverse_rotate(stack_a, 'a');
		swap_stack(stack_a, 'a');
	}
	else if (b < a && a < c)
		swap_stack(stack_a, 'a');
	else if (c < a && a < b)
		reverse_rotate(stack_a, 'a');
	else if (b < c && c < a)
		rotate_stack(stack_a, 'a');
	else if (c < b && b < a)
	{
		swap_stack(stack_a, 'a');
		reverse_rotate(stack_a, 'a');
	}
}

void sort_stack_of_five(t_node **stack_a, t_node **stack_b, int stack_size)
{
	int	count;

	count = 0;
	while (stack_size > 3)
	{
		min_value_to_top_sort(stack_a, stack_b);
		stack_size--;
		count++;
	}
	sort_stack_of_three(stack_a);
	while (count--)
		push_stack(stack_b, stack_a, 'a');	
}
