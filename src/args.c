/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:49:56 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 01:20:36 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>
#include <types.h>

int	args_into_stack(t_stack *s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc - 1)
	{
		push(s, ft_atoi(argv[argc - i - 1]));
		i++;
	}
	return (SUCCESS);
}
