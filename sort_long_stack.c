/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_long_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 17:29:14 by trpham            #+#    #+#             */
/*   Updated: 2025/02/04 16:04:39 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	partition_by_mean(t_node **stack_a, t_node **stack_b, int cal_size,
			char moves[], int i)
{
	long long	mean;

	// if (cal_size <= 5)
	// 	break ;
	mean = find_mean(*stack_a, cal_size);
	if (cal_size > 5)
	{
		if ((long long)(*stack_a)->content <= mean)
			pb(stack_a, stack_b, moves, i);
		else
		{
			ra(stack_a, moves, i);
		}
		cal_size = stack_size_cal(*stack_a);
		i = partition_by_mean(stack_a, stack_b, cal_size, moves, i);
	}
	return (i);
}

t_node	*find_best_friend(t_node *stack_a, int nb)
{
	t_node	*temp_a;
	t_node	*best_friend;
	
	temp_a = stack_a;
	best_friend = NULL;
	while (temp_a)
	{
		if ((temp_a->content) > nb)
		{
			if (!best_friend || temp_a->content < best_friend->content)
				best_friend = temp_a;
		}
		// if (!temp_a->next)
		// 	break;
		temp_a = temp_a->next;
	}
	if (!best_friend) // can not find the best friend, place at the bottom (largest number)
	{
		best_friend = stack_a;
		temp_a = stack_a->next;
		while (temp_a)
		{
			if (temp_a->content > best_friend->content)
				best_friend = temp_a;
			temp_a = temp_a->next;
		}
	}
	return (best_friend);
}

void update_move_info(t_node *stack_a, t_node *stack_b) // update for stack_b
{
	t_node	*temp;
	
	temp = stack_b;
	while (temp)
	{
		temp->moves_to_top = calculate_moves_to_top(stack_b, temp);
		temp->index = find_index(stack_b, temp);
		temp->best_friend = find_best_friend(stack_a, temp->content);
		temp->friend_moves_to_top = calculate_moves_to_top(stack_a, temp->best_friend);
		temp->total_moves = temp->moves_to_top + temp->friend_moves_to_top;
		temp = temp->next;
	}
}

t_node	*find_best_move(t_node *stack_b)
{
	t_node	*best_move;
	t_node	*temp_b;
	
	best_move = stack_b;
	temp_b = stack_b->next;
	while (temp_b)
	{
		if (temp_b->total_moves < best_move->total_moves)
			best_move = temp_b;
		temp_b = temp_b->next;
	}
	return (best_move);
}

int	execute_best_move(t_node **stack_a, t_node **stack_b,
			char moves[], int i)
{
	t_node	*best_move;
	
	update_move_info(*stack_a, *stack_b);
	best_move = find_best_move(*stack_b);
	move_to_top_a(stack_a, best_move->best_friend, moves, i);
	move_to_top_b(stack_b, best_move, moves, i);
	pa(stack_b, stack_a, moves, i);	
	move_to_top_a(stack_a, find_min_node(*stack_a), moves, i);
	return (i);
}


