/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:41:37 by trpham            #+#    #+#             */
/*   Updated: 2025/02/07 14:29:33 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_stack(char	**arr)
{
	t_node	*lst;
	t_node	*temp;
	t_node	*new;

	lst = NULL;
	temp = NULL;
	while (*arr)
	{
		new = ft_doubly_lstnew(ft_atoi_long(*arr));
		if (!lst)
		{
			temp = new;
			lst = new;
		}
		else
		{
			temp->next = new;
			new->prev = temp;
			temp = temp->next;
		}
		arr++;
	}
	return (lst);
}

int	find_index(t_node *stack, t_node *node)
{
	t_node	*temp;	
	int		index;

	index = 0;
	temp = stack;
	while (temp->content != node->content)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

t_node	*find_min_node(t_node *stack)
{
	t_node	*min_node;
	t_node	*temp;

	temp = stack->next;
	min_node = stack;
	while (temp)
	{
		if (min_node->content > temp->content)
			min_node = temp;
		temp = temp->next;
	}
	return (min_node);
}

int	move_to_top_a(t_node **stack_a, t_node *node, char moves[], int i)
{
	int	index;
	int	stack_size;
	int	move_count;

	index = find_index(*stack_a, node);
	stack_size = stack_size_cal(*stack_a);
	if (index <= (stack_size / 2))
	{
		while (index--)
			i = ra(stack_a, moves, i);
	}
	else
	{
		move_count = stack_size - index;
		while (move_count--)
			i = rra(stack_a, moves, i);
	}
	return (i);
}

int	move_to_top_b(t_node **stack_b, t_node *node, char moves[], int i)
{
	int	index;
	int	stack_size;
	int	move_count;

	index = find_index(*stack_b, node);
	stack_size = stack_size_cal(*stack_b);
	if (index <= (stack_size / 2))
	{
		while (index--)
		{
			i = rb(stack_b, moves, i);
		}
	}
	else
	{
		move_count = stack_size - index;
		while (move_count--)
		{
			i = rrb(stack_b, moves, i);
		}
	}
	return (i);
}
