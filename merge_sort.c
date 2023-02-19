/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:32:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 21:32:48 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "merge_sort.h"
#include "operations.h"
#include "optimized_sort.h"
#include "stack.h"

static void	divide_stack(t_stack *s, t_stack *other, size_t half_size,
		t_ops **ops)
{
	size_t	i;

	i = 0;
	while (i < half_size)
	{
		add_push(other, s, ops);
		i++;
	}
}

static void	recover_stack(t_stack *s, size_t recover_size, t_ops **ops)
{
	size_t	i;

	if (recover_size == s->size)
		return ;
	i = 0;
	while (i < recover_size)
	{
		add_reverse(s, ops);
		i++;
	}
}

static size_t	get_half_size(size_t size)
{
	if (size == 4)
		return (1);
	return (size / 2);
}

static void	merge_stack(t_stack *s, t_stack *other, t_msize msize, t_ops **ops)
{
	while (msize.s_size || msize.other_size)
	{
		if ((get_top_n(s, 1) < get_top_n(other, 1) && msize.s_size)
			|| !msize.other_size)
		{
			add_rotate(s, ops);
			msize.s_size--;
		}
		else
		{
			add_push(s, other, ops);
			add_rotate(s, ops);
			msize.other_size--;
		}
	}
	recover_stack(s, msize.sort_size, ops);
}

void	merge_sort(t_stack *s, t_stack *other, size_t sort_size, t_ops **ops)
{
	t_msize	msize;

	if (sort_size <= 3)
	{
		optimized_sort(s, other, sort_size, ops);
		return ;
	}
	msize.sort_size = sort_size;
	msize.other_size = get_half_size(sort_size);
	msize.s_size = sort_size - msize.other_size;
	divide_stack(s, other, msize.other_size, ops);
	merge_sort(s, other, msize.s_size, ops);
	merge_sort(other, s, msize.other_size, ops);
	merge_stack(s, other, msize, ops);
}
