/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:09:00 by trpham            #+#    #+#             */
/*   Updated: 2025/01/16 18:31:44 by trpham           ###   ########.fr       */
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

t_node *swap_stack(t_node *lst)
{
	int	len;
	t_node	*node1;
	t_node	*node2;

	node1 = NULL;
	node2 = NULL;
	// check if the length is at least 2
	if (lst == NULL || lst->next == NULL)
		return (NULL);
	
	//check lst length, can remove
	len = node_lst_size(lst);
	printf("length of stack: %d\n", len);

	// set value for node1 and node2
	node1 = lst;
	// printf("Value of Node1 :%d\n",node1->content);
	node2 = lst->next;
	// printf("Value of Node2 :%d\n",node2->content);

	// swap, but need to ask for more robust option
	node1->next = node2->next;
    node2->next = node1;
    node2->prev = NULL;
    lst = node2;
	return (lst);
}

t_node	*rotate_stack(t_node *lst)
{
	t_node	*temp = NULL;
	t_node	*head = NULL;

	
	if (lst == NULL)
		return (NULL);
	
	head = lst;
	// printf("The head value :%d\n", head->content);
	lst = lst->next;
	// printf("The new head value :%d\n", lst->content);
	lst->prev = NULL;
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
		// printf("The lst value :%d\n", temp->content);
	}
	temp->next = head;
	head->prev = temp;
	head->next = NULL;
	
	return (lst);
}
t_node	*reverse_rotate(t_node *lst)
{
	t_node	*temp;
	t_node	*tail;

	temp = NULL;
	tail = NULL;
	if (lst == NULL)
		return (NULL);
	temp = lst;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	tail = temp;
	// printf("%d\n", tail->content);
	temp->prev->next = NULL;
	tail->next = lst;
	tail->prev = NULL;
	return (tail);
}
