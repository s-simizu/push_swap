/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:31:22 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 03:09:35 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCE_H
# define REDUCE_H

# include <types.h>

bool	cancelled_ops(t_ops *ops, t_op op);
bool	summarized_ops(t_ops *ops, t_op op);
bool	canceled_rotation(t_stack *s, t_op op, t_ops *ops);

#endif
