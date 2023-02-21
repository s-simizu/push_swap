# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:51:14 by sshimizu          #+#    #+#              #
#    Updated: 2023/02/21 19:22:12 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = src
INCLUDE = include
SRCS = args.c                  conditions.c            exit.c \
main.c                  operations_basic.c      operations_summary.c \
operations_utils.c      optimized_sort.c        optimized_step.c \
quick_sort.c            reduce.c                sort_utils.c \
stack_operations.c      stack_utils.c
OBJS = $(SRCS:.c=.o)
LIB = libft
LIBFT = libft.a
CC = cc
CFLAGS = -I$(INCLUDE) -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)/$(LIBFT)

$(LIBFT):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) fclean -C $(LIB)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re
