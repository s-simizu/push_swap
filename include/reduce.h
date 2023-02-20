/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 21:31:22 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/20 22:01:50 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCE_H
# define REDUCE_H

# include <types.h>

bool	cancelled_ops(t_ops *ops, t_op op);
bool	summarized_ops(t_ops *ops, t_op op);

#endif
