/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_step.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:40:00 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 03:52:43 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operations.h>
#include <stack.h>

static void	add_pop(t_stack *s, t_stack *other, t_ops **ops)
{
	add_push(other, s, ops);
}

void	add_step_132(t_stack *s, t_stack *other, t_ops **ops)
{
	add_pop(s, other, ops);
	add_swap(s, other, ops);
	add_push(s, other, ops);
}

void	add_step_231(t_stack *s, t_stack *other, t_ops **ops)
{
	add_pop(s, other, ops);
	add_swap(s, other, ops);
	add_push(s, other, ops);
	add_swap(s, other, ops);
}

void	add_step_312(t_stack *s, t_stack *other, t_ops **ops)
{
	add_swap(s, other, ops);
	add_pop(s, other, ops);
	add_swap(s, other, ops);
	add_push(s, other, ops);
}

void	add_step_321(t_stack *s, t_stack *other, t_ops **ops)
{
	add_swap(s, other, ops);
	add_pop(s, other, ops);
	add_swap(s, other, ops);
	add_push(s, other, ops);
	add_swap(s, other, ops);
}
