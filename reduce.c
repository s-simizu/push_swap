/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:15:56 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 22:21:44 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "reduce.h"

static bool	can_cancel(t_op op1, t_op op2)
{
	if (op1 == SA && op2 == SA)
		return (true);
	if (op1 == SB && op2 == SB)
		return (true);
	if ((op1 == PA && op2 == PB) || (op1 == PB && op2 == PA))
		return (true);
	if ((op1 == RA && op2 == RRA) || (op1 == RRA && op2 == RA))
		return (true);
	if ((op1 == RB && op2 == RRB) || (op1 == RRB && op2 == RB))
		return (true);
	return (false);
}

bool	cancelled_ops(t_ops *ops, t_op op)
{
	if (ops->size == 0)
		return (false);
	if (can_cancel(op, ops->array[ops->size - 1]))
	{
		ops->size--;
		return (true);
	}
	return (false);
}

static bool	can_summarize(t_op op1, t_op op2)
{
	if ((op1 == SA && op2 == SB) || (op1 == SB && op2 == SA))
		return (true);
	if ((op1 == RA && op2 == RB) || (op1 == RB && op2 == RA))
		return (true);
	if ((op1 == RRA && op2 == RRB) || (op1 == RRB && op2 == RRA))
		return (true);
	return (false);
}

static t_op	get_summarize_op(t_op op)
{
	if (op == SA || op == SB)
		return (SS);
	if (op == RA || op == RB)
		return (RR);
	return (RRR);
}

bool	summarized_ops(t_ops *ops, t_op op)
{
	if (ops->size == 0)
		return (false);
	if (can_summarize(op, ops->array[ops->size - 1]))
	{
		ops->array[ops->size - 1] = get_summarize_op(op);
		return (true);
	}
	return (false);
}
