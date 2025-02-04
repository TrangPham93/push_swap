/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/02/04 13:49:54 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**input_arr;
	int		stack_size;
	char	moves[999999];

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		input_arr = ft_handle_input(argc, argv);
		if (input_arr == NULL || ft_valid_input(input_arr) == -1)
		{
			error();
		}
		stack_a = create_stack(input_arr);
		if (argc == 2)
			ft_free_input_arr(input_arr);
		else
			free(input_arr);
		if (stack_a == NULL)
		{
			free_stack(stack_a);
			return (0) ;
		}
		stack_size = stack_size_cal(stack_a);
		ft_sort(&stack_a, &stack_b, stack_size, moves);
	}
	return (0);
}

void	ft_sort(t_node **stack_a, t_node **stack_b, int stack_size,
				char moves[])
{	
	int	i;

	i = 0;
	if (stack_size == 1)
		;
	else if (is_sorted(stack_a))
		;
	else if (stack_size == 2)
		sort_stack_of_two(stack_a, );
	else if (stack_size == 3)
		sort_stack_of_three(stack_a);
	else if (stack_size == 4)
		sort_stack_of_four(stack_a, stack_b);
	else if (stack_size == 5)
		sort_stack_of_five(stack_a, stack_b);
	else
	{
		partition_by_mean(stack_a, stack_b, stack_size);
		sort_stack_of_five(stack_a, stack_b);
		while (*stack_b)
			execute_best_move(stack_a, stack_b);
	}
	print_moves(moves, i);
	free_stack(stack_a);
	free_stack(stack_b);
}

void	print_moves(char moves[], int i)
{
	int	j;
	int	temp;

	j = 0;
	while (j <= i)
	{
		
	}

	
}

int	optimized_move(char	moves[], int i)
{
	
}
int	normal_move(char moves[], int i)
{
	
}