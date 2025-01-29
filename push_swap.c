/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/29 23:17:14 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	*stack_dup(t_node	*stack_a, int size);
int	find_mean(t_node *stack, int size);
void	partition_by_mean(t_node **stack_a, t_node **stack_b, int size);
int	calculate_moves_to_top(t_node *stack, t_node *node);
int	find_index(t_node *stack, t_node *node);
void	execute_best_move(t_node **stack_a, t_node **stack_b);
void	move_to_top(t_node **stack, t_node *node, char c);
t_node	*find_best_friend(t_node *stack_a, int nb);
void update_move_info(t_node *stack_a, t_node *stack_b);
t_node	*find_min_node(t_node *stack);


int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**input_arr;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit (-1);
	input_arr = ft_handle_input(argc, argv);
	if (input_arr == NULL || ft_valid_input(input_arr) == -1)
		error();
	stack_a = create_stack(input_arr);
	free(input_arr);
	// sort with push and rotate only
	ft_sort(&stack_a, &stack_b);
	
	
	// print_list(stack_a);
	// print_list(stack_b);	
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int		stack_size;
	
	if (*stack_a == NULL)
		return ;
	stack_size = node_lst_size(*stack_a);
	if (stack_size == 1)
		return ;
	else if (stack_size == 2) // need to combine with size of 3
		sort_stack_of_two(stack_a);
	else if (stack_size == 3)
		sort_stack_of_three(stack_a);
	else if (stack_size <= 5)
		sort_stack_of_five(stack_a, stack_b, stack_size);
	else
	{
		partition_by_mean(stack_a, stack_b, stack_size);
		sort_stack_of_five(stack_a, stack_b, 5);
		while (*stack_b)
			execute_best_move(stack_a, stack_b);
	}
}


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

int	find_mean(t_node *stack, int size)
{
	float	mean;
	// int		size;
	int		sum;
	t_node	*temp;

	sum = 0;
	temp = stack;
	while (temp)
	{
		sum += temp->content;
		temp = temp->next;
	}
	mean = (float)sum / (float)size;
	return ((int)mean);
}

void	partition_by_mean(t_node **stack_a, t_node **stack_b, int cal_size)
{
	int	mean;

	if (cal_size > 5)
	{
		mean = find_mean(*stack_a, cal_size);
		if ((*stack_a)->content <= mean)
			push_stack(stack_a, stack_b, 'b');
		else
			rotate_stack(stack_a, 'a');
			
		cal_size = node_lst_size(*stack_a);
		partition_by_mean(stack_a, stack_b, cal_size);
	}
}
int	calculate_moves_to_top(t_node *stack, t_node *node)
{
	int	index;
	int	stack_size;

	index = find_index(stack, node);
	// printf("index %d\n", index);
	stack_size = node_lst_size(stack);
	if (index < (stack_size / 2))
		return (index);
	else
		return (stack_size - index);
}

int	find_index(t_node *stack, t_node *node)
{
	t_node	*temp;
	int	index;

	index = 0;
	temp = stack;
	while (temp->content != node->content)
	{
		temp = temp->next;
		index++;
	}
	return (index);
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
void	move_to_top(t_node **stack, t_node *node, char c)
{
	int	index;
	int	stack_size;
	int	move_count;

	index = find_index(*stack, node);
	stack_size = node_lst_size(*stack);
	if (index < (stack_size / 2))
	{
		while (index--)
			rotate_stack(stack, c);
	}
	else
	{
		move_count = stack_size - index;
		while (move_count--)
			reverse_rotate(stack, c);		
	}
}

void	execute_best_move(t_node **stack_a, t_node **stack_b)
{
	t_node	*best_move;
	
	update_move_info(*stack_a, *stack_b);
	best_move = find_best_move(*stack_b);
	move_to_top(stack_a, best_move->best_friend, 'a');	
	move_to_top(stack_b, best_move, 'b');
	push_stack(stack_b, stack_a, 'a');
	move_to_top(stack_a, find_min_node(*stack_a), 'a');
}
t_node	*find_min_node(t_node *stack)
{
	t_node *min_node;
	t_node *temp;

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

