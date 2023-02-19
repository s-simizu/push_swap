/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort_reverse.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:42:48 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 18:20:32 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "conditions.h"
#include "operations.h"
#include "optimized_sort.h"

void	sort_reverse_2(t_stack *s, t_ops **ops)
{
	if (get_top_n(s, 1) > get_top_n(s, 2))
		return ;
	add_swap(s, ops);
}

void	sort_reverse_3_with_rotate(t_stack *s, t_ops **ops)
{
	if (condition_321(s))
		return ;
	if (condition_231(s))
		add_swap(s, ops);
	else if (condition_132(s))
		add_rotate(s, ops);
	else if (condition_213(s))
		add_reverse(s, ops);
	else if (is_sorted_3(s))
	{
		add_swap(s, ops);
		add_reverse(s, ops);
	}
	else if (condition_312(s))
	{
		add_reverse(s, ops);
		add_swap(s, ops);
	}
}

void	sort_reverse_3_without_rotate(t_stack *s, t_stack *other, t_ops **ops)
{
	if (condition_321(s))
		return ;
	if (condition_231(s))
		add_swap(s, ops);
	else if (condition_312(s))
		add_step_132(s, other, ops);
	else if (condition_213(s))
		add_step_231(s, other, ops);
	else if (condition_132(s))
		add_step_312(s, other, ops);
	else if (is_sorted_3(s))
		add_step_321(s, other, ops);
}

void	optimized_sort_reverse(t_stack *s, t_stack *other, size_t sort_size,
		t_ops **ops)
{
	if (sort_size == 1)
		return ;
	if (sort_size == 2)
		sort_reverse_2(s, ops);
	else if (sort_size == 3 && s->size == 3)
		sort_reverse_3_with_rotate(s, ops);
	else if (sort_size == 3 && s->size != 3)
		sort_reverse_3_without_rotate(s, other, ops);
}
