/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:59:06 by trpham            #+#    #+#             */
/*   Updated: 2025/01/24 17:34:45 by trpham           ###   ########.fr       */
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
				// ft_printf("Duplicated: %s\n", arr[i]);
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
	if (ft_not_duplicate_input(input_arr) != 0)
		return (-1);
	i = 0;
	while (input_arr[i])
	{
		if (ft_is_valid_number(input_arr[i]) != 0 || (ft_atoi_long(input_arr[i])
				> INT_MAX || ft_atoi_long(input_arr[i]) < INT_MIN))
			return (-1);
		i++;
	}
	return (0);
}
char	**ft_handle_input(int argc, char *argv[])
{
	int		i;
	char	**input_arr;

	if (argc == 2)
	{
		if (ft_empty_str(argv[1]) == 0)
			return (NULL);
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
void	error(void)
{
	write(2, "Error\n", 6);
	exit (-1);
}