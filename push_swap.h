/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:41:55 by trpham            #+#    #+#             */
/*   Updated: 2025/01/31 19:04:51 by trpham           ###   ########.fr       */
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
	int				moves_to_top;
	struct s_node *best_friend;
	int	friend_moves_to_top;
	int	total_moves;
}	t_node;

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
int			is_sorted(t_node *stack);
char		**ft_handle_input(int argc, char *argv[]);
void		ft_free_input_arr(char **input_arr);
void		error(void);

void	sort_stack_of_three(t_node	**stack_a);
void	sort_stack_of_two(t_node **stack_a);
void sort_stack_of_four(t_node **stack_a, t_node **stack_b);
void sort_stack_of_five(t_node **stack_a, t_node **stack_b);
// void	min_value_to_top_sort(t_node **stack_a, t_node **stack_b);
void	ft_sort(t_node **stack_a, t_node **stack_b, int stack_size);
// int		min_node(t_node **stack_a);

int	*stack_dup(t_node	*stack_a, int size);
long long	find_mean(t_node *stack, int size);
void	partition_by_mean(t_node **stack_a, t_node **stack_b, int size);
int	calculate_moves_to_top(t_node *stack, t_node *node);
int	find_index(t_node *stack, t_node *node);
void	execute_best_move(t_node **stack_a, t_node **stack_b);
void	move_to_top(t_node **stack, t_node *node, char c);
t_node	*find_best_friend(t_node *stack_a, int nb);
void update_move_info(t_node *stack_a, t_node *stack_b);
t_node	*find_min_node(t_node *stack);

#endif