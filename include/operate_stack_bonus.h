/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operate_stack_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:43:38 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 05:35:24 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATE_STACK_BONUS_H
# define OPERATE_STACK_BONUS_H

# include <types.h>

void	exit_error(t_stack *a, t_stack *b, char *op);
bool	operate_stack(t_stack *a, t_stack *b, char *op);
bool	operate_multiple_stack(t_stack *a, t_stack *b, char *op);

#endif
