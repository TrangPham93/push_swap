/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:21:58 by trpham            #+#    #+#             */
/*   Updated: 2025/01/24 18:04:30 by trpham           ###   ########.fr       */
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
int	min_node(t_node **stack_a)
{
	int		min_value;
	int		min_index;
	int		count;
	t_node	*temp;

	if (*stack_a == NULL)
		return (-1);
		
	min_value = (*stack_a)->content;
	count = 0;
	min_index = 0;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (min_value > temp->content)
		{
			min_value = temp->content;
			min_index = count;
		}
		temp = temp->next;
		count++;
	}
	return (min_index);
}
void	min_value_to_top_sort(t_node **stack_a, t_node **stack_b)
{
	int		min_index;
	int		stack_size;
	int		rotate_count;
	
	if (*stack_a == NULL)
		return ;
	stack_size = node_lst_size(*stack_a);
	if ((*stack_a)->next == NULL)
	{
		push_stack(stack_a, stack_b, 'b');
		return ;
	}
	min_index = min_node(stack_a);
	if (min_index == -1)
		return ;
	if (min_index >= (stack_size / 2))
	{
		rotate_count = stack_size - min_index;
		while (rotate_count > 0)
		{
			reverse_rotate(stack_a, 'a');
			rotate_count--;
		}
	}
	else
	{
		while (min_index > 0)
		{
			rotate_stack(stack_a, 'a');
			min_index--;
		}
	}
	push_stack(stack_a, stack_b, 'b');
}