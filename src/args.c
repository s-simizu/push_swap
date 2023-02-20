/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 15:49:56 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 04:54:51 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

static bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r'
		|| c == '\f');
}

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

int	args_into_stack(t_stack *s, int argc, char **argv)
{
	int			i;
	const char	*arg;

	i = 0;
	while (i < argc - 1)
	{
		arg = (const char *)argv[argc - i - 1];
		if (!int_range(arg))
			return (ERROR);
		push(s, ft_atoi(arg));
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
