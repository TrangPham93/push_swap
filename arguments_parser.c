/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:59:06 by trpham            #+#    #+#             */
/*   Updated: 2025/02/06 15:06:39 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

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
	int		i;
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
			error(); // if ft_split fails
		}
	}
	else
	{
		input_arr = malloc(sizeof (char *) * argc);
		if (!input_arr)
			return (NULL);
		i = 0;
		while (i < (argc - 1))
		{
			input_arr[i] = ft_strdup(argv[i + 1]);
			 // duplicate the str, not copy the pointer in case the str is modified
			if (!input_arr[i])
			{
				while (i >= 0)
				{
					free(input_arr[i]);
					i--;
				}
			free(input_arr);
			error();
			}
			i++;
		}
		input_arr[i] = NULL;
	}
	if (ft_valid_input(input_arr) == -1)
	{
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
