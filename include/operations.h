/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:10:55 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/20 22:38:56 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <types.h>

t_ops		*new_ops(int capacity);
void		add_op(t_ops **ops, t_op op);
void		print_ops(t_ops *ops);
void		add_swap(t_stack *s, t_ops **ops);
void		add_push(t_stack *to, t_stack *from, t_ops **ops);
void		add_rotate(t_stack *s, t_ops **ops);
void		add_reverse(t_stack *s, t_ops **ops);
void		add_ss(t_ops **ops);
void		add_rr(t_ops **ops);
void		add_rrr(t_ops **ops);

#endif