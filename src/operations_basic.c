/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:04:42 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 03:41:45 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operations.h>
#include <stack.h>
#include <exit.h>

void	add_swap(t_stack *s, t_stack *other, t_ops *ops)
{
	int result;

	swap(s);
	if (s->name == STACK_A)
		result = add_op(ops, SA);
	else
		result = add_op(ops, SB);
	if (result == ERROR)
		exit_error(s, other, ops);
}

void	add_push(t_stack *to, t_stack *from, t_ops **ops)
{
	int result;

	push(to, pop(from));
	if (to->name == STACK_A)
		result = add_op(ops, PA);
	else
		result = add_op(ops, PB);
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
