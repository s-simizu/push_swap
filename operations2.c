/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:49:14 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/14 12:58:05 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

void	add_ss(t_list **ops)
{
	add_op(ops, "ss");
}

void	add_rr(t_list **ops)
{
	add_op(ops, "rr");
}

void	add_rrr(t_list **ops)
{
	add_op(ops, "rrr");
}

static void	print_op(void *op)
{
	ft_printf("%s\n", (char *)op);
}

void	print_ops(t_list *ops)
{
	ft_lstiter(ops, print_op);
}
