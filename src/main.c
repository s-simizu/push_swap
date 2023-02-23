/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 00:05:49 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/23 23:49:09 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args.h>
#include <exit.h>
#include <operations.h>
#include <quick_sort.h>
#include <sort_utils.h>
#include <stack.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_ops	*ops;

	a = new_stack(STACK_A, argc - 1);
	b = new_stack(STACK_B, argc - 1);
	ops = new_ops(argc * 20);
	if (!a || !b || !ops)
		exit_error(a, b, ops);
	if (args_into_stack(a, argc, argv) == ERROR)
		exit_error(a, b, ops);
	if (compress_coordinates(a->array, a->size) == ERROR)
		exit_error(a, b, ops);
	if (!is_sorted(a))
		quick_sort(a, b, a->size, ops);
	print_ops(ops);
	free_all(a, b, ops);
}
