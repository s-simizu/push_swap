/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:58:53 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 20:18:11 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <operations.h>
#include <optimized_sort.h>
#include <sort_utils.h>
#include <stack.h>

static void	save_to_stack(t_stack *s, t_stack *other, int size, t_ops *ops)
{
	int	i;

	if (s->name == STACK_A && s->size == size)
		return ;
	i = 0;
	if (s->name == STACK_A)
	{
		while (i < size)
		{
			add_rotate(s, other, ops);
			i++;
		}
	}
	else
	{
		while (i < size)
		{
			add_push(other, s, ops);
			add_rotate(other, s, ops);
			i++;
		}
	}
}

static int	get_pivot(t_stack *s, int size)
{
	int	max;
	int	min;
	int	i;

	max = get_top_n(s, 1);
	min = get_top_n(s, 1);
	i = 1;
	while (i < size + 1)
	{
		max = ft_max(get_top_n(s, i), max);
		min = ft_min(get_top_n(s, i), min);
		i++;
	}
	return ((max + min) / 2);
}

static void	reverse_stack(t_stack *s, t_stack *other, int size, t_ops *ops)
{
	int	i;

	if (s->size == size)
		return ;
	i = 0;
	while (i < size)
	{
		add_reverse(s, other, ops);
		i++;
	}
}

static int	divide_by_pivot(t_stack *s, t_stack *other, int sort_size,
		t_ops *ops)
{
	int	pivot;
	int	divided_size;
	int	i;

	pivot = get_pivot(s, sort_size);
	divided_size = 0;
	i = 0;
	while (i < sort_size)
	{
		if (get_top_n(s, 1) > pivot)
			add_push(other, s, ops);
		else
		{
			add_rotate(s, other, ops);
			divided_size++;
		}
		i++;
	}
	reverse_stack(s, other, divided_size, ops);
	return (divided_size);
}

void	quick_sort(t_stack *s, t_stack *other, int sort_size, t_ops *ops)
{
	int	divided_size;

	if (is_sorted(s, sort_size))
	{
		save_to_stack(s, other, sort_size, ops);
		return ;
	}
	if (sort_size <= 3)
	{
		optimized_sort(s, other, sort_size, ops);
		save_to_stack(s, other, sort_size, ops);
		return ;
	}
	divided_size = divide_by_pivot(s, other, sort_size, ops);
	quick_sort(s, other, divided_size, ops);
	quick_sort(other, s, sort_size - divided_size, ops);
}
