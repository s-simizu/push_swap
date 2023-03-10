/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 08:12:07 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/23 20:22:44 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <types.h>

t_stack	*new_stack(t_name name, int capacity);
int		next_index(t_stack *s, int index);
int		prev_index(t_stack *s, int index);
int		get_top_n(t_stack *s, int n);
int		realloc_stack(t_stack *s);
int		push(t_stack *s, int val);
int		pop(t_stack *s);
void	swap(t_stack *s);
void	rotate(t_stack *s);
void	reverse(t_stack *s);

#endif
