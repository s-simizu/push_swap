/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:10:55 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 17:45:46 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

# include "libft/libft.h"
# include "stack.h"

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_op;

typedef struct s_ops
{
	t_op	*array;
	size_t	capacity;
	size_t	size;
}			t_ops;

t_ops		*new_ops(size_t capacity);
void		add_op(t_ops **ops, t_op op);
void		print_ops(t_ops *ops);
void		add_swap(t_stack *s, t_ops **ops);
void		add_push(t_stack *s, t_stack *from, t_ops **ops);
void		add_rotate(t_stack *s, t_ops **ops);
void		add_reverse(t_stack *s, t_ops **ops);
void		add_ss(t_ops **ops);
void		add_rr(t_ops **ops);
void		add_rrr(t_ops **ops);

#endif