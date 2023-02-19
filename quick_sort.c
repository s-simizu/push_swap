/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:58:53 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 18:53:55 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "optimized_sort.h"
#include "quick_sort.h"
#include "stack.h"

void	reverse_stack(t_stack *s, size_t size, t_ops **ops)
{
	size_t	i;

	if (size == s->size)
		return ;
	i = 0;
	while (i < size)
	{
		add_reverse(s, ops);
		i++;
	}
}

size_t	divide_by_pivot(t_stack *s, t_stack *other, size_t sort_size,
		t_ops **ops)
{
	size_t	divided_size;
	size_t	pivot;
	size_t	i;

	pivot = get_top_n(s, 3);
	divided_size = 0;
	i = 0;
	while (i < sort_size)
	{
		if (get_top_n(s, 1) < pivot)
			add_push(other, s, ops);
		else
		{
			add_rotate(s, ops);
			divided_size++;
		}
		i++;
	}
	reverse_stack(s, divided_size, ops);
	return (divided_size);
}

void	restore_stack(t_stack *s, t_stack *other, size_t size, t_ops **ops)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		add_push(s, other, ops);
		i++;
	}
}

void	quick_sort(t_stack *s, t_stack *other, size_t sort_size, t_ops **ops)
{
	size_t	divided_size;

	if (sort_size < 4)
	{
		optimized_sort(s, other, sort_size, ops);
		return ;
	}
	divided_size = divide_by_pivot(s, other, sort_size, ops);
	quick_sort(s, other, divided_size, ops);
	quick_sort_reverse(other, s, sort_size - divided_size, ops);
	restore_stack(s, other, sort_size - divided_size, ops);
}
