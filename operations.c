/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:04:42 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/13 20:14:24 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

void	add_op(t_list **ops, char *str)
{
	t_list	*op;

	op = ft_lstnew(str);
	if (!op)
		exit(1);
	ft_lstadd_back(ops, op);
}

void	add_swap(t_stack *s, t_list **ops)
{
	swap(s);
	if (s->name == STACK_A)
		add_op(ops, "sa");
	else
		add_op(ops, "sb");
}

void	add_push(t_stack *s, t_stack *from, t_list **ops)
{
	push(s, pop(from));
	if (s->name == STACK_A)
		add_op(ops, "pa");
	else
		add_op(ops, "pb");
}

void	add_rotate(t_stack *s, t_list **ops)
{
	if (s->name == STACK_A)
		add_op(ops, "ra");
	else
		add_op(ops, "rb");
}

void	add_reverse(t_stack *s, t_list **ops)
{
	if (s->name == STACK_A)
		add_op(ops, "rra");
	else
		add_op(ops, "rrb");
}
