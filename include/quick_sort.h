/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:53:56 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/20 22:39:11 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUICK_SORT_H
# define QUICK_SORT_H

# include <types.h>

void	quick_sort(t_stack *s, t_stack *other, int sort_size, t_ops **ops);

#endif
