/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/23 13:49:46 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"
#include <stdint.h>

void	min_value_sort(t_node **stack_a, t_node **stack_b);
int	min_node(t_node **stack_a);

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
	
	while (stack_a != NULL)
	{
		ft_printf("Sorting stack_a\n");
		min_value_sort(&stack_a, &stack_b);
		
		ft_printf("After min_value_sort, stack_a: ");
		print_list(stack_a);
		
		ft_printf("stack_b: ");
		print_list(stack_b);
		ft_printf("\n");
	}
	while (stack_b != NULL)
	{
		push_stack(&stack_b, &stack_a);
	}
	
	ft_printf("All elements have been sorted and moved to stack_a.\n");
	print_list(stack_a);
	print_list(stack_b);	
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
// void	sort_3_numbers(t_node	**stack_a)
// {
	
// }


void	min_value_sort(t_node **stack_a, t_node **stack_b)
{
	int		min_index;
	int		stack_size;
	int		rotate_count;
	
	if (*stack_a == NULL)
		return ;
	if ((*stack_a)->next == NULL)
	{
		push_stack(stack_a, stack_b);
		return ;
	}
	stack_size = node_lst_size(*stack_a);
	// ft_printf("%d\n", stack_size);
	min_index = min_node(stack_a);
	// ft_printf("%d\n", min_index);
	// ft_printf("stack a before rotate\n");
	if (min_index == -1)
		return ;
	
	if (min_index >= (stack_size / 2))
	{
		rotate_count = stack_size - min_index;
		while (rotate_count > 0)
		{
			// ft_printf("reverse rotate count %d\n", rotate_count);
			reverse_rotate(stack_a);
			rotate_count--;
		}
		
	}
	else
	{
		while (min_index > 0)
		{
			// ft_printf("rotate count %d\n", min_index);
			rotate_stack(stack_a);
			min_index--;
		}
		
	}
	// ft_printf("rotate min_value to top of stack\n");

	push_stack(stack_a, stack_b);
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
	// ft_printf("min node index %d\n", min_index);
	// ft_printf("min node value %d\n", min_value);
	// print_list(*stack_a);
	return (min_index);
}


// void	push_stack(t_node **stack_1, t_node **stack_2)
// {
// 	t_node	*head;

// 	if (*stack_1 == NULL)
// 		return ;
// 	head = *stack_1;
// 	*stack_1 = (*stack_1)->next;
// 	if (*stack_1 != NULL)
// 		(*stack_1)->prev = NULL;
// 	head->next = (*stack_2);
// 	if (*stack_2 != NULL)
// 		(*stack_2)->prev = head;
// 	head->prev = NULL;
// 	*stack_2 = head;
// }
