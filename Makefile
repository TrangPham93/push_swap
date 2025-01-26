# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: trpham <trpham@student.hive.fi>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 10:30:26 by trpham            #+#    #+#              #
#    Updated: 2025/01/24 19:12:51 by trpham           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS = -Wall -Wextra -Werror -g

SRCS = push_swap.c \
		action.c \
		doubly_lst.c \
		arguments_parser.c \
		push_swap_utils.c \
		quick_sort.c

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

