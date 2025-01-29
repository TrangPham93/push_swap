/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:41:55 by trpham            #+#    #+#             */
/*   Updated: 2025/01/29 20:02:19 by trpham           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/includes/libft.h"
# include "./libft/includes/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;

	int				index;
	int				moves_to_top; // moves required to bring to top
	struct s_node *best_friend;
	int	friend_moves_to_top;
	int	total_moves;
}	t_node;

// typedef struct s_stack
// {
// 	t_node	*head;
// 	t_node	*end;
// 	t_node	**arr;
// 	int	current_level;
// 	int	stack_count;
// }	t_stack;



void	swap_stack(t_node **lst, char	c);
void 	rotate_stack(t_node **lst, char c);
void	reverse_rotate(t_node **lst, char c);
void	push_stack(t_node **stack_1, t_node **stack_2, char	c);
void	reverse_both(t_node **stack_1, t_node	**stack_2);
void	rotate_both(t_node **stack_1, t_node	**stack_2);
void	swap_both(t_node **stack_1, t_node	**stack_2);




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
void		error(void);

void	sort_stack_of_three(t_node	**stack_a);
void	sort_stack_of_two(t_node **stack_a);
void	sort_stack_of_five(t_node **stack_a, t_node **stack_b, int stack_size);
void	min_value_to_top_sort(t_node **stack_a, t_node **stack_b);
void	ft_sort(t_node **stack_a, t_node **stack_b);
int		min_node(t_node **stack_a);
// void	quick_sort(t_node	**stack_a, t_node	**stack_b);

#endif