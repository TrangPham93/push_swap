# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 10:30:26 by trpham            #+#    #+#              #
#    Updated: 2025/10/26 15:44:08 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -g

SRCS = main.c \
		push_swap_utils.c \
		arguments_parser.c \
		arguments_parser_1.c \
		arguments_parser_2.c \
		swap.c \
		rotate.c \
		reverse_rotate.c \
		push.c \
		node_utils.c \
		node_utils_2.c \
		sort_long_stack.c \
		sort_long_stack_helper.c \
		optimize_move.c

OBJS = $(SRCS:%.c=%.o)

NAME = push_swap #create executable instead of static library

LIBFT_DIR = ./libft
LIBFT_NAME = $(LIBFT_DIR)/libft.a

all: $(NAME)

%.o: %.c push_swap.h
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_NAME):
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) $(LIBFT_NAME)
	@$(CC) $(CFLAGS) $^ -o $@
	@echo "Compiled push_swap"

clean:
	@make clean -C $(LIBFT_DIR)
	@rm -f $(OBJS)
	@echo "Clean objs"

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f  $(NAME)

re: fclean all

.PHONY: all clean fclean re

