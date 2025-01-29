/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/28 11:20:21 by trpham           ###   ########.fr       */
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
int	find_pivot(t_node *stack, int size);
void	partition_stack(t_node **stack_a, t_node **stack_b, int pivot, int size);
// void quicksort_stack_a(t_node **stack_a, t_node **stack_b, int size);
// void quicksort_stack_b(t_node **stack_a, t_node **stack_b, int size);
void quicksort_stack(t_node **stack_a, t_node **stack_b, int size);

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
	{
		while (stack_size > 3)
		{
			min_value_to_top_sort(stack_a, stack_b);
			stack_size--;
		}
		sort_stack_of_three(stack_a);
		while (stack_b != NULL && (*stack_b)->next != NULL)
			push_stack(stack_b, stack_a, 'a');
		while ((*stack_b)->next == NULL)
			push_stack(stack_b, stack_a, 'a');
	}
	else
	{
		// partition_stack(stack_a, stack_b, find_pivot(*stack_a, stack_size), stack_size);
		quicksort_stack(stack_a, stack_b, stack_size);
		
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
	return (i + 1);
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
int	find_pivot(t_node *stack, int size)
{
	int	*stack_a_dup;
	int	median;

	stack_a_dup = stack_dup(stack, size);
	quick_sort(stack_a_dup, 0, size - 1);
	// for (int i = 0; i < size; i++)
	// {
	// 	ft_printf("%d ", stack_a_dup[i]);
	// }
	// ft_printf("\n");
	median = stack_a_dup[size / 2]; //if divided by 2 return float
	free(stack_a_dup);
	return (median);

}

void partition_stack(t_node **stack_a, t_node **stack_b, int pivot, int size)
{
    int i = 0;

    while (i < size)
    {
        if (*stack_a == NULL)
            break;
        if ((*stack_a)->content < pivot)
        {
            push_stack(stack_a, stack_b, 'b');  // Push to stack_b if smaller than pivot
        }
        else
        {
            rotate_stack(stack_a, 'a');        // Rotate stack_a if greater than or equal to pivot
        }
        i++;
    }
}

void quicksort_stack(t_node **stack_a, t_node **stack_b, int size)
{
    if (size <= 3)
    {
        // Base case: Directly sort the stack if size is 2 or 3
        if (size == 2)
		{
			printf("sort 2 element of stack\n");
            sort_stack_of_two(stack_a);
			print_list(*stack_a);
		}
        else if (size == 3)
		{
			printf("sort 3 element of stack\n");
            sort_stack_of_three(stack_a);
			print_list(*stack_a);
		}
        return;
    }

    // Find the pivot (you can use median or random element, here using median)
    int pivot = find_pivot(*stack_a, size); // Assumes you have a function to get pivot

    // Partition stack_a into stack_a (>= pivot) and stack_b (< pivot)
    partition_stack(stack_a, stack_b, pivot, size);
	ft_printf("Stack a (larger than pivot): \n ");
	print_list(*stack_a);
	ft_printf("Stack b (smaller than pivot): \n ");
	print_list(*stack_b);

    // Count the number of elements pushed to stack_b
    int count_b = size - node_lst_size(*stack_a);  // Number of elements in stack_b
    int count_a = size - count_b;  // Number of elements in stack_a

    // Recursively sort both parts
    if (count_a > 0)
        quicksort_stack(stack_a, stack_b, count_a); // Recursively sort the larger part in stack_a
    if (count_b > 0)
        quicksort_stack(stack_b, stack_a, count_b); // Recursively sort the smaller part in stack_b

    // After sorting both parts, push back elements from stack_b to stack_a
    while (*stack_b)
    {
        push_stack(stack_b, stack_a, 'a'); // Push sorted elements back into stack_a
    }
}

