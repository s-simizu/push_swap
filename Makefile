# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:51:14 by sshimizu          #+#    #+#              #
#    Updated: 2023/02/23 21:37:27 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRCS = args.c                  conditions.c            exit.c \
main.c                  operations_basic.c      operations_summary.c \
operations_utils.c      optimized_sort.c        optimized_step.c \
quick_sort.c            reduce.c                sort_utils.c \
stack_operations.c      stack_utils.c
OBJS = $(SRCS:.c=.o)
LIB = libft/
LIBFT = libft.a
CC = cc
CFLAGS = -I include -I libft -Wall -Wextra -Werror
VPATH = src include libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)$(LIBFT) -o $@

args.o: libft.h stack.h types.h
conditions.o: stack.h types.h
exit.o: types.h
main.o: args.h exit.h operations.h quick_sort.h sort_utils.h stack.h types.h
operations_basic.o: exit.h operations.h stack.h types.h
operations_summary.o: exit.h operations.h types.h
operations_utils.o: libft.h reduce.h types.h
optimized_sort.o: conditions.h operations.h optimized_step stack.h types.h
optimized_step.o: operations.h stack.h types.h
quick_sort.o: libft.h operations.h optimized_sort.h stack.h types.h
reduce.o: types.h
sort_utils.o: libft.h stack.h types.h
stack_operations.o: stack.h types.h
stack_utils.o: types.h

$(LIBFT):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) fclean -C $(LIB)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
