/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_summary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:49:14 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 03:58:48 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operations.h>

static void	check_add_error(int result, t_stack *s, t_stack *other, t_ops *ops)
{
	if (result == SUCCESS)
		return ;
	exit_error(s, other, ops);
}

void	add_ss(t_stack *s, t_stack *other, t_ops *ops)
{
	check_add_error(add_op(ops, SS), s, other, ops);
}

void	add_rr(t_stack *s, t_stack *other, t_ops *ops)
{
	check_add_error(add_op(ops, RR), s, other, ops);
}

void	add_rrr(t_stack *s, t_stack *other, t_ops *ops)
{
	check_add_error(add_op(ops, RRR), s, other, ops);
}
