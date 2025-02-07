/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimize_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:50:31 by trpham            #+#    #+#             */
/*   Updated: 2025/02/07 14:29:42 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_moves(char moves[], int i)
{
	int	j;
	int	temp;

	j = 0;
	temp = 0;
	while (j <= i && moves[j] != '\0')
	{
		temp = j;
		j = optimized_move(moves, j);
		if (j == temp)
			normal_move(moves, j);
		j++;
	}
}

int	optimized_move(char moves[], int i)
{
	if (moves[i] == '\0' || moves[i + 1] == '\0')
		return (i);
	if ((moves[i] == '1' && moves[i + 1] == '2')
		|| (moves[i] == '2' && moves[i + 1] == '1'))
	{
		write(1, "ss\n", 3);
		i++;
	}
	else if ((moves[i] == '3' && moves[i + 1] == '4')
		|| (moves[i] == '4' && moves[i + 1] == '3'))
	{
		write(1, "rr\n", 3);
		i++;
	}
	else if ((moves[i] == '5' && moves[i + 1] == '6')
		|| (moves[i] == '6' && moves[i + 1] == '5'))
	{
		write(1, "rrr\n", 4);
		i++;
	}
	return (i);
}

void	normal_move(char moves[], int i)
{
	if (moves[i] == '1')
		write(1, "sa\n", 3);
	if (moves[i] == '2')
		write(1, "sb\n", 3);
	if (moves[i] == '3')
		write(1, "ra\n", 3);
	if (moves[i] == '4')
		write(1, "rb\n", 3);
	if (moves[i] == '5')
		write(1, "rra\n", 4);
	if (moves[i] == '6')
		write(1, "rrb\n", 4);
	if (moves[i] == '7')
		write(1, "pb\n", 3);
	if (moves[i] == '8')
		write(1, "pa\n", 3);
}
