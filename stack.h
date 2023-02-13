/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:12:07 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/13 19:08:35 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_name
{
	STACK_A,
	STACK_B
}			t_name;

typedef struct s_stack
{
	t_name	name;
	int		*array;
	size_t	capacity;
	size_t	size;
	size_t	top;
	size_t	bottom;
}			t_stack;

t_stack		*new_stack(t_name name, size_t capacity);
size_t		next_index(t_stack *s, size_t index);
size_t		prev_index(t_stack *s, size_t index);
int			get_top_n(t_stack *s, size_t n);
void		free_stack(t_stack *s);
void		push(t_stack *s, int val);
int			pop(t_stack *s);
void		swap(t_stack *s);
void		rotate(t_stack *s);
void		reverse(t_stack *s);

#endif