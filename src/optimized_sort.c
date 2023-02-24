/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:02:46 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 20:17:37 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <conditions.h>
#include <operations.h>
#include <optimized_step.h>
#include <stack.h>

static void	sort_3_with_rotate(t_stack *s, t_stack *other, t_ops *ops)
{
	if (condition_213(s))
		add_swap(s, other, ops);
	else if (condition_312(s))
		add_rotate(s, other, ops);
	else if (condition_231(s))
		add_reverse(s, other, ops);
	else if (condition_321(s))
	{
		add_rotate(s, other, ops);
		add_swap(s, other, ops);
	}
	else if (condition_132(s))
	{
		add_swap(s, other, ops);
		add_rotate(s, other, ops);
	}
}

static void	sort_3_without_rotate(t_stack *s, t_stack *other, t_ops *ops)
{
	if (condition_213(s))
		add_swap(s, other, ops);
	else if (condition_132(s))
		add_step_132(s, other, ops);
	else if (condition_231(s))
		add_step_231(s, other, ops);
	else if (condition_312(s))
		add_step_312(s, other, ops);
	else if (condition_321(s))
		add_step_321(s, other, ops);
}

void	optimized_sort(t_stack *s, t_stack *other, int sort_size, t_ops *ops)
{
	if (sort_size == 2)
		add_swap(s, other, ops);
	else if (sort_size == 3 && s->size == 3)
		sort_3_with_rotate(s, other, ops);
	else if (sort_size == 3 && s->size != 3)
		sort_3_without_rotate(s, other, ops);
}
