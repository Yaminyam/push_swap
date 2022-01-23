# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sikang <sikang@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/23 01:57:32 by sikang            #+#    #+#              #
#    Updated: 2022/01/23 02:02:37 by sikang           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	$(MAKE) bonus -C libft

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

$(NAME): push_swap.o libft
	$(CC) -o $@ $< -Llibft -lft

.PHONY: all bonus libft clean fclean re
