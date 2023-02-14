/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conditions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 19:19:06 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/14 07:47:13 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

bool	condition_213(t_stack *s)
{
	return (get_top_n(s, 2) < get_top_n(s, 1) && get_top_n(s,
			1) < get_top_n(s, 3));
}

bool	condition_312(t_stack *s)
{
	return (get_top_n(s, 2) < get_top_n(s, 3) && get_top_n(s,
			3) < get_top_n(s, 1));
}

bool	condition_231(t_stack *s)
{
	return (get_top_n(s, 3) < get_top_n(s, 1) && get_top_n(s,
			1) < get_top_n(s, 2));
}

bool	condition_321(t_stack *s)
{
	return (get_top_n(s, 3) < get_top_n(s, 2) && get_top_n(s,
			2) < get_top_n(s, 1));
}

bool	condition_132(t_stack *s)
{
	return (get_top_n(s, 1) < get_top_n(s, 3) && get_top_n(s,
			3) < get_top_n(s, 2));
}
