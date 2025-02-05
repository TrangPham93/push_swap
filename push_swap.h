/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 10:41:55 by trpham            #+#    #+#             */
/*   Updated: 2025/02/05 13:00:22 by trpham           ###   ########.fr       */
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
	struct s_node	*best_friend;
	int				friend_moves_to_top;
	int				total_moves;
}	t_node;

void		swap_stack(t_node **lst);
int			sa(t_node **stack_a, char moves[], int i);
int			rb(t_node **stack_b, char moves[], int i);
void		rr(t_node **stack_a, t_node **stack_b);

void		rotate_stack(t_node **lst);
int			ra(t_node **stack_a, char moves[], int i);
int			rb(t_node **stack_b, char moves[], int i);
void		rr(t_node **stack_a, t_node **stack_b);

void		reverse_rotate(t_node **lst);
int			rra(t_node **stack_a, char moves[], int i);
int			rrb(t_node **stack_b, char moves[], int i);
void		rrr(t_node **stack_a, t_node **stack_b);

void		push_stack(t_node **stack_1, t_node **stack_2);
// Take the first element at the top of a and put it at the top of b.
int			pb(t_node **stack_a, t_node **stack_b, char moves[], int i);
// Take the first element at the top of b and put it at the top of a.
int			pa(t_node **stack_b, t_node **stack_a, char moves[], int i);

int			stack_size_cal(t_node *lst);
void		print_list(t_node *lst);
void		free_stack(t_node *lst);
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

int			sort_stack_of_two(t_node **stack_a, char moves[], int i);
int			sort_stack_of_three(t_node	**stack_a, char moves[], int i);
int 		sort_stack_of_four(t_node **stack_a, t_node **stack_b, char moves[],
				int i);
int	 		sort_stack_of_five(t_node **stack_a, t_node **stack_b, char moves[],
				int i);
void		ft_sort(t_node **stack_a, t_node **stack_b, int stack_size,
				char moves[]);

int			move_to_top_a(t_node **stack_a, t_node *node, char moves[], int i);
int			move_to_top_b(t_node **stack_b, t_node *node, char moves[], int i);
int			partition_by_mean(t_node **stack_a, t_node **stack_b, int cal_size,
				char moves[], int i);
int			execute_best_move(t_node **stack_a, t_node **stack_b, char moves[],
				int i);
int			optimized_move(char	moves[], int i);
void		normal_move(char	moves[], int i);

int			find_index(t_node *stack, t_node *node);
t_node		*find_min_node(t_node *stack);
t_node		*find_best_friend(t_node *stack_a, int nb);
int			*stack_dup(t_node	*stack_a, int size);
long long	find_mean(t_node *stack, int size);
int			calculate_moves_to_top(t_node *stack, t_node *node);

void		print_moves(char moves[], int i);
void 		update_move_info(t_node *stack_a, t_node *stack_b);

#endif