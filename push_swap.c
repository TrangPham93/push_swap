/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/27 18:40:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	*stack_dup(t_node	*stack_a, int size);
void	quick_sort(int	*stack_dup, int low, int high);
int	partition(int *stack, int low, int high);
void	assign_stack_index(t_node **stack_a, int size);
void execute_moves(t_node **stack_a, t_node **stack_b, int move_a, int move_b);
int find_optimal_move(int *moves_a, int *moves_b, int size_b);
int find_position(t_node *stack_a, int index);
void calculate_moves(t_node *stack_a, t_node *stack_b, int *moves_a, int *moves_b);
void assign_stack_index(t_node **stack_a, int size);

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
	{
		while (stack_size > 3)
		{
			min_value_to_top_sort(stack_a, stack_b);
			stack_size--;
		}
		sort_stack_of_three(stack_a);
		while (stack_b != NULL && (*stack_b)->next != NULL)
			push_stack(stack_b, stack_a, 'a');
		if ((*stack_b)->next == NULL)
			push_stack(stack_b, stack_a, 'a');
	}
	else
	{
		assign_stack_index(stack_a, stack_size);
		while (stack_size > 3)
		{
			push_stack(stack_a, stack_b, 'b');
			stack_size--;
		}
		sort_stack_of_three(stack_a);
		// print_list(*stack_a);
		// ft_printf("%d\n", (*stack_b)->index);
		// print_list(*stack_b);	
		while (*stack_b)
		{
			int size_b = node_lst_size(*stack_b);
			int *moves_a = malloc(size_b * sizeof(int));
			int *moves_b = malloc(size_b * sizeof(int));

			// Calculate moves for all elements in stack B
			calculate_moves(*stack_a, *stack_b, moves_a, moves_b);

			// Find the optimal element to push
			int optimal_index = find_optimal_move(moves_a, moves_b, size_b);

			// Execute the moves for the optimal element
			execute_moves(stack_a, stack_b, moves_a[optimal_index], moves_b[optimal_index]);

			// Free the allocated memory
			free(moves_a);
			free(moves_b);
		}
	}
}

void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp; 
}
int	*stack_dup(t_node	*stack_a, int size)
{
	// int		size;
	int		*stack_a_dup;
	t_node	*temp;
	int		i;
	
	// size = node_lst_size(stack_a);
	stack_a_dup = malloc((size) * sizeof(int));
	if (!stack_a_dup)
		return (NULL);
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

int	partition(int *stack, int low, int high)
{
	int	pivot;
	int	i;
	int	j;
	
	pivot = stack[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (stack[j] < pivot)
		{
			i++;
			swap_int(&stack[i], &stack[j]);
		}
		j++;
	}
	swap_int(&stack[i + 1], &stack[high]);	
	return (i);
}
void	quick_sort(int	*stack, int low, int high)
{
	int	pivot_index;
	
	if (low < high)
	{
		pivot_index = partition(stack, low, high);
		quick_sort(stack, low, pivot_index - 1);
		quick_sort(stack, pivot_index + 1, high); 
	}
}
