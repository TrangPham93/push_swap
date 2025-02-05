/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:04:33 by trpham            #+#    #+#             */
/*   Updated: 2025/02/05 19:40:52 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	stack_size_cal(t_node *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	print_list(t_node *lst)
{
	if (lst == NULL)
		return ;
	while (lst)
	{
		printf("%d ", lst->content);
		lst = lst->next;
	}
	printf("\n");
}

void	free_stack(t_node *lst)
{
	t_node	*temp;

	temp = lst;
	while (lst)
	{
		temp = lst;
		lst = lst->next;
		free(temp);
	}
}

t_node	*ft_doubly_lstnew(int content)
{
	t_node	*temp;

	temp = (t_node *)malloc(sizeof(t_node));
	if (temp == NULL)
		return (NULL);
	temp ->content = content;
	temp ->next = NULL;
	temp ->prev = NULL;
	return (temp);
}

t_node	*create_stack(char	**arr)
{
	t_node	*lst;
	t_node	*temp;
	t_node	*new;

	lst = NULL;
	temp = NULL;
	while (*arr)
	{
		new = ft_doubly_lstnew(ft_atoi_long(*arr));
		if (!lst)
		{
			temp = new;
			lst = new;
		}
		else
		{
			temp->next = new;
			new->prev = temp;
			temp = temp->next;
		}
		arr++;
	}
	return (lst);
}

int	find_index(t_node *stack, t_node *node)
{
	t_node	*temp;	
	int	index;

	index = 0;
	temp = stack;
	while (temp->content != node->content)
	{
		temp = temp->next;
		index++;
	}
	return (index);
}

t_node	*find_min_node(t_node *stack)
{
	t_node *min_node;
	t_node *temp;

	temp = stack->next;
	min_node = stack;
	while (temp)
	{
		if (min_node->content > temp->content)
			min_node = temp;	
		temp = temp->next;
	}
	return (min_node);
}

int move_to_top_a(t_node **stack_a, t_node *node, char moves[], int i)
{
	int	index;
	int	stack_size;
	int	move_count;

	index = find_index(*stack_a, node);
	// printf("min node index %d\n", index);
	stack_size = stack_size_cal(*stack_a);
	if (index <= (stack_size / 2))
	{
		while (index--)
			i = ra(stack_a, moves, i);
	}
	else
	{
		move_count = stack_size - index;
		while (move_count--)
			i = rra(stack_a, moves, i);
	}
	return (i);
}
int	move_to_top_b(t_node **stack_b, t_node *node, char moves[], int i)
{
	int	index;
	int	stack_size;
	int	move_count;

	index = find_index(*stack_b, node);
	stack_size = stack_size_cal(*stack_b);
	// printf("best move  %d, its index %d & stack size %d\n", node->content, index, stack_size);
	if (index <= (stack_size / 2))
	{
		while (index--)
		{
			// printf("rotate stack b\n");
			i = rb(stack_b, moves, i);
			// printf("i that need to be roated in b %d\n", i);
		}
	}
	else
	{
		move_count = stack_size - index;
		while (move_count--)
		{
			// printf("reverse rotate stack b\n");
			i = rrb(stack_b, moves, i);
		}
	}
	return (i);
}