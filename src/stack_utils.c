/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:04:15 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 05:25:02 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <types.h>

t_stack	*new_stack(t_name name, int capacity)
{
	t_stack	*s;
	int		*array;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	array = malloc(capacity * sizeof(int));
	if (!array)
	{
		free(s);
		return (NULL);
	}
	s->name = name;
	s->array = array;
	s->capacity = capacity;
	s->size = 0;
	s->top = 0;
	s->bottom = 0;
	return (s);
}

int	next_index(t_stack *s, int index)
{
	return ((index + 1) % s->capacity);
}

int	prev_index(t_stack *s, int index)
{
	return ((index + s->capacity - 1) % s->capacity);
}

int	get_top_n(t_stack *s, int n)
{
	int	index;

	if (n > s->size)
		return (0);
	if (n > s->capacity)
		n %= s->capacity;
	index = (s->top + s->capacity - n) % s->capacity;
	return (s->array[index]);
}
