# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 10:30:26 by trpham            #+#    #+#              #
#    Updated: 2025/02/04 14:41:56 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap.c \
		push_swap_utils.c \
		arguments_parser.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		push.c \
		node_utils.c \
		sort_long_stack.c \
		sort_long_stack_helper.c

OBJS = $(SRCS:%.c=%.o)

NAME = push_swap #create executable instead of static library

LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_NAME)
	$(CC) $(CFLAGS) $^ -o $@
#	ar rcs $(NAME) $^ 

clean:
	@make clean -C $(LIBFT_DIR)
	rm -f $(OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re

