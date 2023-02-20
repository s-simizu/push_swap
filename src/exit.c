/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:30:52 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 01:38:14 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <types.h>
#include <unistd.h>

static void	print_error(void)
{
	write(2, "Error\n", 6);
}

static void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}

static void	free_ops(t_ops *ops)
{
	free(ops->array);
	free(ops);
}

void	free_all(t_stack *a, t_stack *b, t_ops *ops)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	if (ops)
		free_ops(ops);
}

void	exit_error(t_stack *a, t_stack *b, t_ops *ops)
{
	free_all(a, b, ops);
	print_error();
	exit(1);
}
