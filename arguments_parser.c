/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:59:06 by trpham            #+#    #+#             */
/*   Updated: 2025/02/06 16:40:59 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	ft_empty_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
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
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (-1);
	}
	return (0);
}

int	is_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (-1);
	temp = stack;
	while (temp->next)
	{
		if (temp->content < temp->next->content)
			temp = temp->next;
		else
			return (-1);
	}
	return (0);
}

t_node	*ft_handle_input(int argc, char *argv[])
{
	char	**input_arr;
	t_node	*stack;

	if (argc == 2)
	{
		if (ft_empty_str(argv[1]) == 0)
			error();
		input_arr = ft_split(argv[1], ' ');
		if (!input_arr)
		{
			ft_free_input_arr(input_arr);
			error();
		}
	}
	else
		input_arr = handle_multiple_input(argc, argv);
	if (ft_valid_input(input_arr) == -1)
	{
		printf("failing valid input check \n");
		error();
	}
	stack = create_stack(input_arr);
	ft_free_input_arr(input_arr);
	return (stack);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit (-1);
}
char	**handle_multiple_input(int	argc, char *argv[])
{
	int	count;
	// int	i;
	char	**input_arr;

	// i = 0;
	count = count_multiple_input(argc, argv);
	input_arr = malloc(sizeof (char *) * (count + 1));
	if (!input_arr)
		error ();
	convert_multiple_input_arr(argc, argv, input_arr);
	return (input_arr);
}
void	convert_multiple_input_arr(int argc, char *argv[], char **input_arr)
{
	int	i;
	int	j;
	int	k;
	char	**str;
	
	i = 1;
	j = 0;
	while (i < argc)
	{
		if ( !argv[i] || ft_empty_str(argv[i]) == 0)
			error();
		str = ft_split(argv[i], ' ');
		if (!str)
		{
			ft_free_input_arr(str);
			error();
		}
		k = 0;
		while (str[k])
		{
			input_arr[j] = ft_strdup(str[k]);
			if (!input_arr[j])
				ft_free_input_arr(input_arr);
			k++;
			j++;
		}
		i++;
		ft_free_input_arr(str);
	}
	input_arr[j] = NULL;
}

int	count_multiple_input(int argc, char *argv[])
{
	int	i;
	int	j;
	int	count;
	char	**input_arr;

	i = 0;
	count = 0;
	while (i < argc)
	{
		if (!argv[i] || ft_empty_str(argv[i + 1]) == 0)
			error();
		input_arr = ft_split(argv[i + 1], ' ');
		if (!input_arr)
		{
			ft_free_input_arr(input_arr);
			error();
		}
		j = 0;
		while (input_arr[j])
			j++;
		count += j;
		ft_free_input_arr(input_arr);
		i++;
	}
	return (count);
}
