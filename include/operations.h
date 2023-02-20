/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:10:55 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 03:59:17 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include <types.h>

t_ops	*new_ops(int capacity);
int		add_op(t_ops **ops, t_op op);
void	print_ops(t_ops *ops);
void	add_swap(t_stack *s, t_stack *other, t_ops *ops);
void	add_push(t_stack *to, t_stack *from, t_ops *ops);
void	add_rotate(t_stack *s, t_stack *other, t_ops *ops);
void	add_reverse(t_stack *s, t_stack *other, t_ops *ops);
void	add_ss(t_stack *s, t_stack *other, t_ops *ops);
void	add_rr(t_stack *s, t_stack *other, t_ops *ops);
void	add_rrr(t_stack *s, t_stack *other, t_ops *ops);

#endif