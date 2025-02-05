/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_stack_helper.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:31:39 by trpham            #+#    #+#             */
/*   Updated: 2025/02/05 17:40:04 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	*stack_dup(t_node	*stack_a, int size)
{
	int		*stack_a_dup;
	t_node	*temp;
	int		i;
	
	stack_a_dup = malloc((size) * sizeof(int));
	if (!stack_a_dup)
		exit (-1);
	temp = stack_a;
	i = 0;
	while (temp != NULL)
	{
		stack_a_dup[i] = temp->content;
		temp = temp->next;
		i++;
	}
	return (stack_a_dup);
}

long long	find_mean(t_node *stack, int size)
{
	long long	mean;
	long long		sum;
	t_node	*temp;

	sum = 0;
	temp = stack;
	while (temp)
	{
		sum += temp->content;
		temp = temp->next;
	}
	mean = sum / size;
	return (mean);
}

int	calculate_moves_to_top(t_node *stack, t_node *node)
{
	int	index;
	int	stack_size;

	// printf("debugging move to top \n");
	index = find_index(stack, node);
	// printf("node value %d, node index %d \n", node->content, node->index);
	stack_size = stack_size_cal(stack);
	// printf("stack_b size %d\n", stack_size);
	if (index <= (stack_size / 2))
	{
		
		// printf("calculate moves to top %d\n",index );
		return ((int)index);
	}
	else
	{
		// printf("calculate moves to top %d\n", stack_size - index);
		return (stack_size - index);

	}
}
