/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:31:00 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 17:37:03 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <reduce.h>
#include <stdlib.h>

t_ops	*new_ops(int capacity)
{
	t_ops	*ops;

	ops = malloc(sizeof(t_ops));
	if (!ops)
		return (NULL);
	ops->array = malloc(capacity * sizeof(t_op));
	if (!ops->array)
	{
		free(ops);
		return (NULL);
	}
	ops->capacity = capacity;
	ops->size = 0;
	return (ops);
}

static int	realloc_ops(t_ops *ops)
{
	t_op	*new_array;
	int		new_size;

	new_size = ft_min(ops->capacity * sizeof(t_op) * 2, INT_MAX);
	new_array = malloc(new_size);
	if (!new_array)
	{
		free(ops->array);
		free(ops);
		return (ERROR);
	}
	ft_memcpy(new_array, ops->array, ops->capacity * sizeof(t_op));
	free(ops->array);
	ops->array = new_array;
	ops->capacity = ops->capacity * 2;
	ops->size = ops->capacity;
	return (SUCCESS);
}

int	add_op(t_ops *ops, t_op op)
{
	if (cancelled_ops(ops, op))
		return (SUCCESS);
	if (summarized_ops(ops, op))
		return (SUCCESS);
	if (ops->size == ops->capacity)
	{
		if (realloc_ops(ops) == ERROR)
			return (ERROR);
	}
	ops->array[ops->size] = op;
	ops->size++;
	return (SUCCESS);
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
	int	i;

	i = 0;
	while (i < ops->size)
	{
		print_op(ops->array[i]);
		i++;
	}
}
