/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 21:31:57 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/03 04:04:10 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include "stack.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_list	*inst;

	if (argc == 1)
		return (0);
	if (argc == 2)
		a = get_stack_split(argv[1]);
	else
		a = get_stack(argv);
	b = new_stack();
	inst = quick_sort(a, b);
	optimize(inst);
	print_inst(inst);
	free_all(inst);
}
