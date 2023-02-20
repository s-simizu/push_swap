/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_summary.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:49:14 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/20 22:06:49 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <operations.h>

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
