/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:04:15 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/13 18:22:15 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(t_name name, size_t capacity)
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

size_t	next_index(t_stack *s, size_t index)
{
	return ((index + 1) % s->capacity);
}

size_t	prev_index(t_stack *s, size_t index)
{
	return ((index + s->capacity - 1) % s->capacity);
}

int	get_top_n(t_stack *s, size_t n)
{
	size_t	index;

	if (n > s->capacity)
		n %= s->capacity;
	index = (s->top + s->capacity - n) % s->capacity;
	return (s->array[index]);
}

void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}