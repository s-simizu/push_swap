/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 21:32:02 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/13 22:37:32 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "optimized_sort.h"
#include "stack.h"

// merge_sort()
// {
//     divide(a);
//     merge_sort(a);
//     merge_sort(b);
//     merge(a, b);
// }

static void	optimized_sort(t_stack *s, t_stack *other, size_t sort_size,
		t_list **ops)
{
	if (sort_size == 1)
		return ;
	if (sort_size == 2)
		sort_2(s, ops);
	else if (sort_size == 3 && s->size == 3)
		sort_3_with_rotate(s, ops);
	else if (sort_size == 3 && s->size != 3)
		sort_3_without_rotate(s, other, ops);
}

static void	divide_stack(t_stack *s, t_stack *other, size_t half_size,
		t_list **ops)
{
	size_t	i;

	i = 0;
	while (i < half_size)
	{
		add_push(other, s, ops);
		i++;
	}
}

static void	merge_stack(t_stack *s, t_stack *other, size_t sort_size,
		t_list **ops)
{
	size_t	i;

	i = 0;
	while (i < sort_size)
	{
		if (get_top_n(s, 1) > get_top_n(other, 1))
			add_push(s, other, ops);
		add_rotate(s, ops);
		i++;
	}
}

void	merge_sort(t_stack *s, t_stack *other, size_t sort_size, t_list **ops)
{
	size_t	half_size;

	if (sort_size <= 3)
	{
		optimized_sort(s, other, sort_size, ops);
		return ;
	}
	if (sort_size == 4)
		half_size = 1;
	else
		half_size = sort_size / 2;
	divide_stack(s, other, half_size, ops);
	merge_sort(s, other, sort_size - half_size, ops);
	merge_sort(other, s, half_size, ops);
	merge_stack(s, other, sort_size, ops);
}
