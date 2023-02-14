/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:02:46 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/14 08:31:12 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"
#include "operations.h"
#include "optimized_sort.h"

void	sort_2(t_stack *s, t_list **ops)
{
	t_list	*op;

	if (get_top_n(s, 1) < get_top_n(s, 2))
		return ;
	add_swap(s, ops);
}

bool	is_sorted_3(t_stack *s)
{
	return (get_top_n(s, 1) < get_top_n(s, 2) && get_top_n(s, 2) < get_top_n(s,
			3));
}

void	sort_3_with_rotate(t_stack *s, t_list **ops)
{
	if (is_sorted_3(s))
		return ;
	if (condition_213(s))
		add_swap(s, ops);
	else if (condition_312(s))
		add_rotate(s, ops);
	else if (condition_231(s))
		add_reverse(s, ops);
	else if (condition_321(s))
	{
		add_swap(s, ops);
		add_reverse(s, ops);
	}
	else if (condition_132(s))
	{
		add_reverse(s, ops);
		add_swap(s, ops);
	}
}

void	sort_3_without_rotate(t_stack *s, t_stack *other, t_list **ops)
{
	if (is_sorted_3(s))
		return ;
	if (condition_213(s))
		add_swap(s, ops);
	else if (condition_132(s))
		add_step_132(s, other, ops);
	else if (condition_231(s))
		add_step_231(s, other, ops);
	else if (condition_312(s))
		add_step_312(s, other, ops);
	else if (condition_321(s))
		add_step_321(s, other, ops);
}

void	optimized_sort(t_stack *s, t_stack *other, size_t sort_size,
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
