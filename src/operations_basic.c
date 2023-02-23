/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_basic.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:04:42 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/23 20:53:54 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <exit.h>
#include <operations.h>
#include <stack.h>

static void	check_add_error(int result, t_stack *s, t_stack *other, t_ops *ops)
{
	if (result == ERROR)
		exit_error(s, other, ops);
}

void	add_swap(t_stack *s, t_stack *other, t_ops *ops)
{
	swap(s);
	if (s->name == STACK_A)
		check_add_error(add_op(ops, SA), s, other, ops);
	else
		check_add_error(add_op(ops, SB), s, other, ops);
}

void	add_push(t_stack *to, t_stack *from, t_ops *ops)
{
	check_add_error(push(to, pop(from)), to, from, ops);
	if (to->name == STACK_A)
		check_add_error(add_op(ops, PA), to, from, ops);
	else
		check_add_error(add_op(ops, PB), to, from, ops);
}

void	add_rotate(t_stack *s, t_stack *other, t_ops *ops)
{
	rotate(s);
	if (s->name == STACK_A)
		check_add_error(add_op(ops, RA), s, other, ops);
	else
		check_add_error(add_op(ops, RB), s, other, ops);
}

void	add_reverse(t_stack *s, t_stack *other, t_ops *ops)
{
	reverse(s);
	if (s->name == STACK_A)
		check_add_error(add_op(ops, RRA), s, other, ops);
	else
		check_add_error(add_op(ops, RRB), s, other, ops);
}
