/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_reverse.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:53:00 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 18:54:06 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "optimized_sort.h"
#include "quick_sort.h"
#include "stack.h"

size_t	divide_by_pivot_reverse(t_stack *s, t_stack *other, size_t sort_size,
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
		if (get_top_n(s, 1) > pivot)
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

void	quick_sort_reverse(t_stack *s, t_stack *other, size_t sort_size,
		t_ops **ops)
{
	size_t	divided_size;

	if (sort_size < 4)
	{
		optimized_sort_reverse(s, other, sort_size, ops);
		return ;
	}
	divided_size = divide_by_pivot_reverse(s, other, sort_size, ops);
	quick_sort_reverse(s, other, divided_size, ops);
	quick_sort(other, s, sort_size - divided_size, ops);
	restore_stack(s, other, sort_size - divided_size, ops);
}
