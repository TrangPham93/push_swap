/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/22 18:21:13 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"
#include <stdint.h>

void	quick_sort(t_node **stack_a, t_node **stack_b);
int	min_node(t_node *lst);

char	**ft_handle_input(int argc, char *argv[])
{
	int		i;
	char	**input_arr;

	if (argc == 1)
		return (NULL);
	else if (argc == 2)
	{
		if (ft_empty_str(argv[1]) == 0)
		{
			ft_printf("Error: Empty string\n");
			return (NULL);
		}
		input_arr = ft_split(argv[1], ' ');
	}
	else
	{
		input_arr = malloc(sizeof (char *) * argc);
		if (!input_arr)
			return (NULL);
		i = 0;
		while (i < (argc - 1))
		{
			input_arr[i] = argv[i + 1];
			i++;
		}
		input_arr[i] = '\0';
	}
	return (input_arr);
}

t_node	*ft_sort(t_node *stack_a)
{
	
	
	return (stack_a);	
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**input_arr;

	stack_a = NULL;
	stack_b = NULL;
	input_arr = ft_handle_input(argc, argv);
	if (input_arr == NULL || ft_valid_input(input_arr) == -1)
	{
		ft_printf("Error: please input a valid argument \n");
		return (-1);
	}
	stack_a = create_stack(input_arr);
	ft_sort(stack_a);
	// print list
	printf("Print original lst:\n");
	print_list(stack_a);
	// printf("%d\n", min_node(stack_a));
	quick_sort(&stack_a, &stack_b);
	// test function
	// 
	// stack_a = swap_stack(stack_a);
	// printf("After swap:\n");
	// print_list(stack_a);
	// printf("ROTATION:\n");
	// stack_a = rotate_stack(stack_a);
	// print_list(stack_a);
	// printf("Reversed ROTATION:\n");
	// stack_a = reverse_rotate(stack_a);
	// print_list(stack_a);
	// printf("PUSH\n");
	// push_stack(&stack_a, &stack_b);
	// push_stack(&stack_a, &stack_b);
	// print_list(stack_a);
	// print_list(stack_b);
	// free_list(stack_a);
	// free_list(stack_b);
	return (0);
}

void	quick_sort(t_node **stack_a, t_node **stack_b)
{
	int	min;
	t_node	*head;

	head = NULL;
	
	if (node_lst_size(*stack_a) == 1)
		return ;
	min = min_node(*stack_a);
	ft_printf("Min in stack a: %d\n", min);
	if (head->content != min)
	
	push_stack(stack_a, stack_b);
}

int	min_node(t_node *lst)
{
	int		min_value;
	int		min_index = 1;
	t_node	*temp;

	if (lst != NULL)
		min_value = lst->content;
	// temp = lst;
	while (lst->next)
	{
		// temp = temp->next;
		
		if (min_value > temp->content)
			min_value = temp->content;
	}
	return (min_value);
}
