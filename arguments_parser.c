/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:59:06 by trpham            #+#    #+#             */
/*   Updated: 2025/02/07 14:29:27 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		error();
	stack = create_stack(input_arr);
	ft_free_input_arr(input_arr);
	return (stack);
}

char	**handle_multiple_input(int argc, char *argv[])
{
	int		count;
	char	**input_arr;

	count = count_multiple_input(argc, argv);
	input_arr = malloc(sizeof (char *) * (count + 1));
	if (!input_arr)
		error ();
	convert_multiple_input_arr(argc, argv, input_arr);
	return (input_arr);
}

void	convert_multiple_input_arr(int argc, char *argv[], char **input_arr)
{
	int		i;
	int		j;
	int		k;
	char	**str;

	i = 0;
	j = 0;
	while (++i < argc)
	{
		str = ft_split(argv[i], ' ');
		if (!str)
		{
			ft_free_input_arr(str);
			error();
		}
		k = -1;
		while (str[++k])
		{
			input_arr[j] = ft_strdup(str[k]);
			if (!input_arr[j++])
				ft_free_input_arr(input_arr);
		}
		ft_free_input_arr(str);
	}
	input_arr[j] = NULL;
}

int	count_multiple_input(int argc, char *argv[])
{
	int		i;
	int		j;
	int		count;
	char	**input_arr;

	i = 1;
	count = 0;
	while (i < argc)
	{
		if (!argv[i] || ft_empty_str(argv[i]) == 0)
			error();
		input_arr = ft_split(argv[i], ' ');
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
