# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 14:51:14 by sshimizu          #+#    #+#              #
#    Updated: 2023/02/24 05:41:11 by sshimizu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
B_NAME = checker

SRCS = args.c                  conditions.c            exit.c \
main.c                  operations_basic.c      operations_summary.c \
operations_utils.c      optimized_sort.c        optimized_step.c \
quick_sort.c            reduce.c                reduce_rotation.c \
sort_utils.c            stack_operations.c      stack_utils.c

B_SRCS = args.c                main_bonus.c            operate_stack_bonus.c \
sort_utils.c            stack_operations.c      stack_utils.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)
LIB = libft/
LIBFT = libft.a
CC = cc
CFLAGS = -I include -I libft -Wall -Wextra -Werror
VPATH = src include libft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)$(LIBFT) -o $@

debug: CFLAGS += -fsanitize=address
debug: $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIB)$(LIBFT) -o $(NAME)

bonus: $(B_NAME)

$(B_NAME): $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIB)$(LIBFT) -o $@

debug-bonus: CFLAGS += -fsanitize=address
debug-bonus: $(B_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(B_OBJS) $(LIB)$(LIBFT) -o $(B_NAME)

rm:
	rm -f $(NAME)
	rm -f $(B_NAME)

args.o: libft.h stack.h types.h
conditions.o: stack.h types.h
exit.o: types.h
main.o: args.h exit.h operations.h quick_sort.h sort_utils.h stack.h types.h
operations_basic.o: exit.h operations.h stack.h types.h
operations_summary.o: exit.h operations.h types.h
operations_utils.o: libft.h reduce.h types.h
optimized_sort.o: conditions.h operations.h optimized_step.h stack.h types.h
optimized_step.o: operations.h stack.h types.h
quick_sort.o: libft.h operations.h optimized_sort.h stack.h types.h
reduce.o: types.h
reduce_rotation.o: types.h
sort_utils.o: libft.h stack.h types.h
stack_operations.o: stack.h types.h
stack_utils.o: types.h

main_bonus.o: args.h libft.h operate_stack_bonus.h sort_utils.h stack.h types.h
operate_stack_bonus.o: libft.h stack.h types.h

$(LIBFT):
	$(MAKE) -C $(LIB)

clean:
	$(MAKE) fclean -C $(LIB)
	rm -f $(OBJS)
	rm -f $(B_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f $(B_NAME)

re: fclean all

.PHONY: all clean fclean re debug rm bonus debug-bonus
