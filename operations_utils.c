/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:31:00 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 22:18:34 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "operations.h"
#include "reduce.h"

t_ops	*new_ops(size_t capacity)
{
	t_ops	*ops;

	ops = malloc(sizeof(t_ops));
	if (!ops)
		error();
	ops->array = malloc(capacity * sizeof(t_op));
	if (!ops->array)
	{
		free(ops);
		error();
	}
	ops->capacity = capacity;
	ops->size = 0;
	return (ops);
}

static void	realloc_ops(t_ops **ops)
{
	t_ops	*new;

	new = new_ops((*ops)->capacity * 2);
	if (!new)
	{
		free((*ops)->array);
		free(*ops);
		error();
	}
	ft_memcpy(new->array, (*ops)->array, (*ops)->capacity * sizeof(t_op));
	new->capacity = (*ops)->capacity * 2;
	new->size = (*ops)->capacity;
	free((*ops)->array);
	free(*ops);
	*ops = new;
}

void	add_op(t_ops **ops, t_op op)
{
	if (cancelled_ops(*ops, op))
		return ;
	if (summarized_ops(*ops, op))
		return ;
	if ((*ops)->size == (*ops)->capacity)
		realloc_ops(ops);
	(*ops)->array[(*ops)->size] = op;
	(*ops)->size++;
}

static void	print_op(t_op op)
{
	if (op == SA)
		ft_printf("sa\n");
	else if (op == SB)
		ft_printf("sb\n");
	else if (op == SS)
		ft_printf("ss\n");
	else if (op == PA)
		ft_printf("pa\n");
	else if (op == PB)
		ft_printf("pb\n");
	else if (op == RA)
		ft_printf("ra\n");
	else if (op == RB)
		ft_printf("rb\n");
	else if (op == RR)
		ft_printf("rr\n");
	else if (op == RRA)
		ft_printf("rra\n");
	else if (op == RRB)
		ft_printf("rrb\n");
	else if (op == RRR)
		ft_printf("rrr\n");
}

void	print_ops(t_ops *ops)
{
	size_t	i;

	i = 0;
	while (i < ops->size)
	{
		print_op(ops->array[i]);
		i++;
	}
}
