/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:04:33 by trpham            #+#    #+#             */
/*   Updated: 2025/01/30 17:38:09 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"

int	node_lst_size(t_node *lst)
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

void	free_list(t_node *lst)
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

int	min_node(t_node **stack_a)
{
	int		min_value;
	int		min_index;
	int		count;
	t_node	*temp;

	if (*stack_a == NULL)
		return (-1);
		
	min_value = (*stack_a)->content;
	count = 0;
	min_index = 0;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (min_value > temp->content)
		{
			min_value = temp->content;
			min_index = count;
		}
		temp = temp->next;
		count++;
	}
	return (min_index);
}

void	min_value_to_top_sort(t_node **stack_a, t_node **stack_b)
{
	int		min_index;
	int		stack_size;
	int		rotate_count;
	
	if (*stack_a == NULL)
		return ;
	stack_size = node_lst_size(*stack_a);
	if ((*stack_a)->next == NULL)
	{
		push_stack(stack_a, stack_b, 'b');
		return ;
	}
	min_index = min_node(stack_a);
	if (min_index == -1)
		return ;
	if (min_index >= (stack_size / 2))
	{
		rotate_count = stack_size - min_index;
		while (rotate_count > 0)
		{
			reverse_rotate(stack_a, 'a');
			rotate_count--;
		}
	}
	else
	{
		while (min_index > 0)
		{
			rotate_stack(stack_a, 'a');
			min_index--;
		}
	}
	push_stack(stack_a, stack_b, 'b');
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

void	move_to_top(t_node **stack, t_node *node, char c)
{
	int	index;
	int	stack_size;
	int	move_count;

	index = find_index(*stack, node);
	stack_size = node_lst_size(*stack);
	if (index < (stack_size / 2))
	{
		while (index--)
			rotate_stack(stack, c);
	}
	else
	{
		move_count = stack_size - index;
		while (move_count--)
			reverse_rotate(stack, c);		
	}
}
