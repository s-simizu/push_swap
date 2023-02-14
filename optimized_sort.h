/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_sort.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:00:33 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/14 08:35:02 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZED_SORT_H
# define OPTIMIZED_SORT_H

# include "operations.h"
# include "stack.h"

void	add_step_132(t_stack *s, t_stack *other, t_list **ops);
void	add_step_231(t_stack *s, t_stack *other, t_list **ops);
void	add_step_312(t_stack *s, t_stack *other, t_list **ops);
void	add_step_321(t_stack *s, t_stack *other, t_list **ops);
// void	sort_2(t_stack *s, t_list **ops);
// void	sort_3_with_rotate(t_stack *s, t_list **ops);
// void	sort_3_without_rotate(t_stack *s, t_stack *other, t_list **ops);
void	optimized_sort(t_stack *s, t_stack *other, size_t sort_size,
			t_list **ops);

#endif
