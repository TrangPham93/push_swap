/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/24 18:26:48 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	quick_sort(t_node	**stack_a, t_node	**stack_b);

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
	else if (stack_size == 2)
		sort_stack_of_two(stack_a);
	else if (stack_size == 3)
		sort_stack_of_three(stack_a);
	else
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
}

// void	quick_sort(t_node	**stack_a, t_node	**stack_b)
// {
	
// }

// int	partition()
// {
	
// }

// int	find_median(t_node	*stack_a)
// {
	
// }
