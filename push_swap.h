/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:41:55 by trpham            #+#    #+#             */
/*   Updated: 2025/01/23 12:02:58 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

void	swap_stack(t_node **lst);
void rotate_stack(t_node **lst);
void	reverse_rotate(t_node **lst);
void		push_stack(t_node **stack_1, t_node **stack_2);

int			node_lst_size(t_node *lst);
void		print_list(t_node *lst);
void		free_list(t_node *lst);
t_node		*ft_doubly_lstnew(int content);
t_node		*create_stack(char	**arr);

int			ft_empty_str(char *str);
int			ft_is_valid_number(char	*str);
int			ft_not_duplicate_input(char **arr);
long long	ft_atoi_long(const char *nptr);
int			ft_valid_input(char **input_arr);
char		**ft_handle_input(int argc, char *argv[]);

#endif