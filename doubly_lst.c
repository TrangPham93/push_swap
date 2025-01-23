/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:04:33 by trpham            #+#    #+#             */
/*   Updated: 2025/01/23 12:42:21 by trpham           ###   ########.fr       */
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
