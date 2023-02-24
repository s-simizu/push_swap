/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 04:07:30 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/24 17:43:34 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <args.h>
#include <libft.h>
#include <operate_stack_bonus.h>
#include <sort_utils.h>
#include <stack.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	if (argc == 1)
		return (0);
	a = new_stack(STACK_A, argc - 1);
	b = new_stack(STACK_B, argc - 1);
	if (!a || !b)
		exit_error(a, b, NULL);
	if (args_into_stack(a, argc, argv) == ERROR)
		exit_error(a, b, NULL);
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (!operate_stack(a, b, op) && !operate_multiple_stack(a, b, op))
			exit_error(a, b, op);
		free(op);
		op = get_next_line(STDIN_FILENO);
	}
	if (is_sorted(a, a->size) && b->size == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
