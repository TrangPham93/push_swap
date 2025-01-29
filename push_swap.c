/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/29 16:21:02 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	*stack_dup(t_node	*stack_a, int size);
int	find_mean(t_node *stack, int size);
void	partition_by_mean(t_node **stack_a, t_node **stack_b, int size);

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	// t_list	*command;
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
	
	
	print_list(stack_a);
	print_list(stack_b);	
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int		stack_size;
	// int	*stack_a_dup;
	
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
	// size = node_lst_size(stack);
	temp = stack;
	while (temp)
	{
		sum += temp->content;
		temp = temp->next;
	}
	mean = (float)sum / (float)size;
	// printf("mean : %.2f\n", mean);
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
		// print_list(*stack_a);
		// print_list(*stack_b);
			
		cal_size = node_lst_size(*stack_a);
		// printf("stack_a size : %d\n", cal_size);
		partition_by_mean(stack_a, stack_b, cal_size);
	}
}
int	cost_to_top(t_node *stack, int	nb)
{
	int	index;
	int	stack_size;
	int	cost_to_top;

	index = find_index(stack, nb);
	stack_size = node_lst_size(stack);
	if (index < (stack_size / 2))
		cost_to_top = index;
	else
		cost_to_top = stack_size - index;
	return (cost_to_top);		
}

int	find_index(t_node *stack, int nb)
{
	t_node	*temp;
	int	index;

	index = 0;
	temp = stack;
	while (temp->content != nb)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

int	*find_best_friend(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp_a;
	t_node	*temp_b;
	t_node	*best_friend;
	int	nb;
	int	lowest;
	int *best_friend_arr;
	int	i = 0;

	best_friend_arr = malloc(sizeof(t_node) * node_lst_size(stack_b));
	if (!best_friend_arr)
		return (NULL);
	temp_a = stack_a;
	while (*temp_b)
	{
		nb = (*stack_a)->content;
		temp_a = stack_a;
		lowest = INT_MAX;
		while (temp_a)
		{
			if ((temp_a->content - nb) > 0 && (temp_a->content) < lowest)
			{
				best_friend = temp_a;
				lowest = temp_a->content - nb;
			}
			temp_a = temp_a->next;
		}
		best_friend_arr[i] = best_friend->content;
		i++;		
		temp_b = temp_b->next;
	}
	free(best_friend_arr);
	return (t_node);
}
	
void	dd(t_node **stack_a, t_node **stack_b)
{
	int	total_cost = 0;
	int	min_cost;
	t_node *temp_b;
	int cost_a;
	int	cost_b;
	int	i = 0;
	int	*best_friend_arr;
	int	nb_a;
	int	nb_b;

	temp_b = stack_b;
	best_friend_arr = find_best_friend(stack_a, stack_b);
	min_cost += cost_to_top(stack_a; best_friend_arr[i]);
	min_cost += cost_to_top(stack_b, (*stack_b)->content);
	while (temp_b)
	{
		cost_a = cost_to_top(stack_a; best_friend_arr[i]);
		cost_b = cost_to_top(stack_b, (*stack_b)->content);
		if (cost_a + cost_b < min_cost)
		{
			nb_a = *best_friend_arr;
			nb_b = *temp_b;
		}
		best_friend_arr++;
		temp_b = temp_b->next;
	}
	// temp_b = stack_b;
	
	
}





