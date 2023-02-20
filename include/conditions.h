/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:32 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/20 22:00:41 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONDITIONS_H
# define CONDITIONS_H

# include <types.h>

bool	condition_213(t_stack *s);
bool	condition_312(t_stack *s);
bool	condition_231(t_stack *s);
bool	condition_321(t_stack *s);
bool	condition_132(t_stack *s);

#endif
