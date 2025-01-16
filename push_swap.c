/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:34:57 by trpham            #+#    #+#             */
/*   Updated: 2025/01/16 18:31:32 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/includes/libft.h"
#include "./libft/includes/ft_printf.h"
#include <stdint.h>

void ft_handle_input(int argc, char *argv[])
{
	// t_node	lst;
	int	i = 0;
	char	**int_arr;

	printf("%d and %s\n", argc, argv[1]);
	if (argc == 2 && *argv[1] == '\0')
		return ;
	int_arr = ft_split(argv[1], ' ');
	// argc += 1;
	while (int_arr[i])
	{
		printf("%s\n", int_arr[i]);
		i++;
	}
	
	
}

// char **ft_arg_split(char *str)
// {
// 	char	**int_arr;

// 	int_arr = ft_split(str, ' ');
// 	return (int_arr);
// }

int	main(int argc, char *argv[])
{
	// int		i;
	// t_node	*stack_a;
	// t_node	*new;
	// t_node	*lst;
	// t_node	*stack_b;
	// int		num;
	char *str = NULL;

	// i = 0;
	// lst = NULL;
	// stack_a = NULL;
	// stack_b = NULL;

	// if no parameters are specified, display nothing
	if (argc == 1)
		return (-1);
	// handle the argument and return a list
	else if (argc > 1)
	{
		ft_handle_input(argc, argv);


		// while (++i < argc)
		// {
		// 	if (ft_is_valid_number(argv[i]) == 0)
		// 	{
		// 		num = ft_atoi(argv[i]);
		// 		new = ft_doubly_lstnew(num);

		// 		if (!head)
		// 		{
		// 			head = new;
		// 			lst = head;
		// 		}
		// 		else
		// 		{
		// 			lst->next = new;
		// 			new->prev = lst;
		// 			lst = lst->next;
		// 		}
		// 	}
		// 	else
		// 	{
		// 		printf("Error\n");
		// 		free_list(head);
		// 		return (-1);
		// 	}
		// }
	}
	printf("%s\n", str);
	// printf("Print original lst:\n");
	// // lst = head;
	// print_list(head);
	
	// head = swap_stack(head);
	// printf("After swap:\n");
	// print_list(head);
	
	// printf("ROTATION:\n");
	// head = rotate_stack(head);
	// print_list(head);

	
	// printf("Reversed ROTATION:\n");
	// head = reverse_rotate(head);
	// print_list(head);

	// printf("PUSH\n");
	// push_stack(&head, &stack_b);
	// print_list(head);
	// print_list(stack_b);

	
	// lst = head;
	// free_list(lst);
	
	return (0);
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

int ft_is_valid_number(char	*str)
{
	int	i;

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
void print_list(t_node *lst)
{
	if (!lst)
		return ;
	while (lst)
		{
			printf("%d ", lst->content);
			lst = lst->next;
		}
	printf("\n");
}
void free_list(t_node *lst)
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
