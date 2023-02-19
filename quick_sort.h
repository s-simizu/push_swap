/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:53:56 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 18:49:59 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include "operations.h"
# include "stack.h"

void	reverse_stack(t_stack *s, size_t size, t_ops **ops);
void	restore_stack(t_stack *s, t_stack *other, size_t size, t_ops **ops);
void	quick_sort(t_stack *s, t_stack *other, size_t sort_size,
			t_ops **ops);
void	quick_sort_reverse(t_stack *s, t_stack *other, size_t sort_size,
			t_ops **ops);

#endif
