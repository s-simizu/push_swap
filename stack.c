/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:47:45 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/02 22:40:12 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_elem	*push(t_stack s, t_elem *e)
{
	if (!e)
		return (NULL);
	e->next = s.top;
	s.top = e;
	if (!s.bottom)
		s.bottom = e;
}

t_elem	*pop(t_stack s)
{
	t_elem	*e;

	if (!s.top)
		return (NULL);
	e = s.top;
	if (!(s.top->next))
		s.bottom = NULL;
	s.top = s.top->next;
	return (e);
}

void	swap(t_stack s)
{
	t_elem	*a;
	t_elem	*b;

	a = pop(s);
	b = pop(s);
	push(s, a);
	push(s, b);
}

void	rotate(t_stack s)
{
	t_elem	*e;

	if (!s.top || !((s.top)->next))
		return ;
	e = pop(s);
	e->next = NULL;
	s.bottom->next = e;
	s.bottom = e;
}

void	reverse(t_stack s)
{
	t_elem	*bottom;

	if (!s.top || !((s.top)->next))
		return ;
	bottom = s.top;
	while (bottom->next->next != NULL)
		bottom = bottom->next;
	push(s, s.bottom);
	s.bottom = bottom;
}
