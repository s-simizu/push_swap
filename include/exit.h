/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 17:32:19 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 01:40:06 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <types.h>

void	free_all(t_stack *a, t_stack *b, t_ops *ops);
void	exit_error(t_stack *a, t_stack *b, t_ops *ops);

#endif
