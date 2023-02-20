/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:58:04 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 01:18:00 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>
# include <stddef.h>

# define SUCCESS 0
# define ERROR -1

typedef enum e_name
{
	STACK_A,
	STACK_B
}			t_name;

typedef struct s_stack
{
	t_name	name;
	int		*array;
	int		capacity;
	int		size;
	int		top;
	int		bottom;
}			t_stack;

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
	int		capacity;
	int		size;
}			t_ops;

#endif
