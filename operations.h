/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:10:55 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/13 20:14:47 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft/libft.h"
# include "stack.h"

void	add_op(t_list **ops, char *op);
void	add_swap(t_stack *s, t_list **ops);
void	add_push(t_stack *s, t_stack *from, t_list **ops);
void	add_rotate(t_stack *s, t_list **ops);
void	add_reverse(t_stack *s, t_list **ops);
void	add_ss(t_list **ops);
void	add_rr(t_list **ops);
void	add_rrr(t_list **ops);
void	print_ops(t_list *ops);

#endif