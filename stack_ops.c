/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:02:25 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/13 14:58:55 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	push(t_stack *s, int val)
{
	if (s->size == s->capacity)
		return ;
	s->array[s->top] = val;
	s->top = next_index(s, s->top);
	s->size++;
}

int	pop(t_stack *s)
{
	if (s->size == 0)
		return (0);
	s->top = prev_index(s, s->top);
	s->size--;
	return (s->array[s->top]);
}

void	swap(t_stack *s)
{
	int	a;
	int	b;

	if (s->size < 2)
		return ;
	a = pop(s);
	b = pop(s);
	push(s, a);
	push(s, b);
}

void	rotate(t_stack *s)
{
	int	val;

	if (s->size < 2)
		return ;
	s->top = prev_index(s, s->top);
	s->bottom = prev_index(s, s->bottom);
	s->array[s->bottom] = s->array[s->top];
}

void	reverse(t_stack *s)
{
	int	val;

	if (s->size < 2)
		return ;
	s->array[s->top] = s->array[s->bottom];
	s->bottom = next_index(s, s->bottom);
	s->top = next_index(s, s->top);
}
