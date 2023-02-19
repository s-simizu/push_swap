/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:49:14 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 17:44:02 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "operations.h"
#include "stack.h"

void	add_ss(t_ops **ops)
{
	add_op(ops, SS);
}

void	add_rr(t_ops **ops)
{
	add_op(ops, RR);
}

void	add_rrr(t_ops **ops)
{
	add_op(ops, RRR);
}
