/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/17 17:02:29 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"
#include <stdint.h>

int	ft_empty_str(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] != 32)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_is_valid_number(char	*str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			i++;
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);	
}

int	ft_not_duplicate_input(char **arr)
{
	int	i;
	int	j;

	if (*arr == NULL)
		return (-1);
	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) == 0)
			{
				ft_printf("Duplicated: %s\n", arr[i]);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

long long	ft_atoi_long(const char *nptr)
{
	int			i;
	long long	result;
	int			sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	ft_valid_input(char **input_arr)
{
	int	i;

	i = 0;
	if (ft_not_duplicate_input(input_arr) != 0) // check if input contains duplicate
	{
		ft_printf("Error: Duplicate input\n");
		return (-1);
	}
	i = 0;
	while (input_arr[i]) // check if input contains not integer number
	{
		if (ft_is_valid_number(input_arr[i]) != 0 || 
			(ft_atoi_long(input_arr[i]) > INT_MAX || ft_atoi_long(input_arr[i]) < INT_MIN))
		{
			ft_printf("Error: Not valid integers\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

char	**ft_handle_input(int argc, char *argv[])
{
	int		i;
	char	**input_arr;

	if (argc == 1)	// if no parameters are specified, display nothing
		return (NULL);
	else if (argc == 2) // arg is a string
	{
		if (ft_empty_str(argv[1]) == 0) // check if input is an empty string or contains only spaces
		{
			ft_printf("Error: Empty string\n");
			return (NULL);
		}
		input_arr = ft_split(argv[1], ' '); // if not empty string, split the string
	}
	else // arg is a list of arg
	{
		input_arr = malloc(sizeof(char	*) * argc);
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

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	char	**input_arr;

	stack_a = NULL;
	stack_b = NULL;

	input_arr = ft_handle_input(argc, argv);	// handle the argument and return an array
	if (input_arr == NULL || ft_valid_input(input_arr) == -1)
	{
		ft_printf("Error: please input a valid argument \n");
		return (-1);
	}
	stack_a = create_stack(input_arr); // create stack_a
	
	// test function
	printf("Print original lst:\n");
	print_list(stack_a);
	
	stack_a = swap_stack(stack_a);
	printf("After swap:\n");
	print_list(stack_a);
	
	printf("ROTATION:\n");
	stack_a = rotate_stack(stack_a);
	print_list(stack_a);

	printf("Reversed ROTATION:\n");
	stack_a = reverse_rotate(stack_a);
	print_list(stack_a);

	printf("PUSH\n");
	push_stack(&stack_a, &stack_b);
	print_list(stack_a);
	print_list(stack_b);

	free_list(stack_a);
	free_list(stack_b);
	
	return (0);
}
