/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 15:47:58 by sshimizu          #+#    #+#             */
/*   Updated: 2023/01/31 21:44:14 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_elem
{
	int				value;
	struct s_elem	*next;
}					t_elem;

typedef struct s_stack
{
	t_elem			*top;
	t_elem			*bottom;
}					t_stack;

#endif STACK_H
