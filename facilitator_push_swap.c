/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   facilitator_push_swap.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 16:59:06 by trpham            #+#    #+#             */
/*   Updated: 2025/01/17 17:08:38 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
