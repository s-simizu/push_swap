/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:04:42 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 17:44:11 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

void	add_swap(t_stack *s, t_ops **ops)
{
	swap(s);
	if (s->name == STACK_A)
		add_op(ops, SA);
	else
		add_op(ops, SB);
}

void	add_push(t_stack *s, t_stack *from, t_ops **ops)
{
	push(s, pop(from));
	if (s->name == STACK_A)
		add_op(ops, PA);
	else
		add_op(ops, PB);
}

void	add_rotate(t_stack *s, t_ops **ops)
{
	rotate(s);
	if (s->name == STACK_A)
		add_op(ops, RA);
	else
		add_op(ops, RB);
}

void	add_reverse(t_stack *s, t_ops **ops)
{
	reverse(s);
	if (s->name == STACK_A)
		add_op(ops, RRA);
	else
		add_op(ops, RRB);
}
