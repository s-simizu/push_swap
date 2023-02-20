/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimized_step.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:14:10 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 03:55:25 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZED_STEP_H
# define OPTIMIZED_STEP_H

# include <types.h>

void	add_step_132(t_stack *s, t_stack *other, t_ops *ops);
void	add_step_231(t_stack *s, t_stack *other, t_ops *ops);
void	add_step_312(t_stack *s, t_stack *other, t_ops *ops);
void	add_step_321(t_stack *s, t_stack *other, t_ops *ops);

#endif
