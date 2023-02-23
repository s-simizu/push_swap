/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:36:31 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 05:35:14 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

static void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}

void	exit_error(t_stack *a, t_stack *b, char *op)
{
	free_stack(a);
	free_stack(b);
	free(op);
	write(2, "Error\n", 6);
	exit(1);
}

static void	check_push_error(int result, t_stack *a, t_stack *b, char *op)
{
	if (result == ERROR)
		exit_error(a, b, op);
}

bool	operate_stack(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(op, "pa\n", 3) == 0)
		check_push_error(push(a, pop(b)), a, b, op);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		check_push_error(push(b, pop(a)), a, b, op);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		reverse(a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		reverse(b);
	else
		return (false);
	return (true);
}

bool	operate_multiple_stack(t_stack *a, t_stack *b, char *op)
{
	if (ft_strncmp(op, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(op, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
	{
		reverse(a);
		reverse(b);
	}
	else
		return (false);
	return (true);
}
