/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_parser_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:50:11 by trpham            #+#    #+#             */
/*   Updated: 2025/02/06 14:53:45 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

void	ft_free_input_arr(char **input_arr)
{
	int	count;

	count = 0;
	while (input_arr[count])
		count++;
	while (count--)
		free(input_arr[count]);
	free(input_arr);
}

int	ft_not_duplicate_input(char **arr)
{
	int	i;
	int	j;

	if (arr == NULL || *arr == NULL)
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
	{
		ft_free_input_arr(input_arr);
		return (-1);
	}
	i = 0;
	while (input_arr[i])
	{
		if (ft_is_valid_number(input_arr[i]) != 0 || (ft_atoi_long(input_arr[i])
				> INT_MAX || ft_atoi_long(input_arr[i]) < INT_MIN))
		{
			ft_free_input_arr(input_arr);
			return (-1);
		}
		i++;
	}
	return (0);
}
