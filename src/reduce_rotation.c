/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 03:03:04 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 03:17:15 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <types.h>

static int	count_repeated_op(t_op op, t_ops *ops)
{
	int	counter;
	int	i;

	counter = 0;
	i = 1;
	while (i <= ops->size)
	{
		if (ops->array[ops->size - i] != op)
			break ;
		counter++;
        i++;
	}
	return (counter);
}

bool	canceled_rotation(t_stack *s, t_op op, t_ops *ops)
{
	int	repeated;

	repeated = count_repeated_op(op, ops);
	if (repeated != s->size - 1)
		return (false);
	ops->size -= repeated;
	return (true);
}
