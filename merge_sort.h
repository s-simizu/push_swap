/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 22:24:32 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/19 18:31:33 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_SORT_H
# define MERGE_SORT_H

# include "operations.h"
# include "stack.h"

typedef struct s_merge_size
{
	size_t	sort_size;
	size_t	s_size;
	size_t	other_size;
}			t_msize;

void		merge_sort(t_stack *s, t_stack *other, size_t sort_size,
				t_ops **ops);

#endif
