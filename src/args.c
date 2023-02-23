/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:49:56 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/23 23:47:35 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

static long	get_sign(const char *s, size_t *index)
{
	long	sign;

	sign = 1;
	while (ft_isspace(s[*index]))
		(*index)++;
	if (ft_isdigit(s[*index]))
		return (sign);
	if (s[*index] == '-')
		sign = -1;
	(*index)++;
	return (sign);
}

static bool	int_range(const char *s)
{
	long	n;
	long	sign;
	size_t	i;

	n = 0;
	i = 0;
	sign = get_sign(s, &i);
	while (s[i] != '\0')
	{
		if (!ft_isdigit(s[i]))
			return (false);
		n *= 10;
		n += (s[i] - '0') * sign;
		if (n > INT_MAX || n < INT_MIN)
			return (false);
		i++;
	}
	return (true);
}

static int	free_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (ERROR);
}

static int	push_args(t_stack *s, const char *str)
{
	char	**splited;
	int		val;
	int		i;

	splited = ft_split(str, ' ');
	if (!splited)
		return (ERROR);
	i = 0;
	while (splited[i + 1])
		i++;
	while (i >= 0)
	{
		if (!int_range(splited[i]))
			return (free_strs(splited));
		val = ft_atoi(splited[i]);
		if (ft_search_index(val, s->array, s->size) >= 0)
			return (free_strs(splited));
		if (push(s, val) == ERROR)
			return (free_strs(splited));
		i--;
	}
	free_strs(splited);
	return (SUCCESS);
}

int	args_into_stack(t_stack *s, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (push_args(s, argv[argc - i]) == ERROR)
			return (ERROR);
		i++;
	}
	return (SUCCESS);
}

// #include <stdio.h>
// int	main(void)
// {
// 	const char	*s;

// 	s = "2147483647";
// 	printf("%d\n", int_range(s));
// 	s = "2147483648";
// 	printf("%d\n", int_range(s));
// 	s = "-2147483648";
// 	printf("%d\n", int_range(s));
// 	s = "-2147483649";
// 	printf("%d\n", int_range(s));
// 	s = "1315123134513616341635314513";
// 	printf("%d\n", int_range(s));
// 	s = "-1315123134513616341635314513";
// 	printf("%d\n", int_range(s));
// 	s = "1323512fsf";
// 	printf("%d\n", int_range(s));
// 	s = "         +1323512";
// 	printf("%d\n", int_range(s));
// 	s = " 0";
// 	printf("%d\n", int_range(s));
// }
