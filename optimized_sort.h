/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:00:33 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 18:21:14 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZED_SORT_H
# define OPTIMIZED_SORT_H

# include "operations.h"
# include "stack.h"

bool	is_sorted_3(t_stack *s);
void	add_step_132(t_stack *s, t_stack *other, t_ops **ops);
void	add_step_231(t_stack *s, t_stack *other, t_ops **ops);
void	add_step_312(t_stack *s, t_stack *other, t_ops **ops);
void	add_step_321(t_stack *s, t_stack *other, t_ops **ops);
void	optimized_sort(t_stack *s, t_stack *other, size_t sort_size,
			t_ops **ops);
void	optimized_sort_reverse(t_stack *s, t_stack *other, size_t sort_size,
			t_ops **ops);

#endif
