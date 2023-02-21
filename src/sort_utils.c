/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:20:30 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 19:17:37 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stack.h>

static int	*get_sorted_array(int *array, int size)
{
	int	*sorted;

	sorted = malloc(size * sizeof(int));
	if (!sorted)
		return (NULL);
	ft_memcpy(sorted, array, size * sizeof(int));
	ft_bubble_sort(sorted, size);
	return (sorted);
}

int	compress_coordinates(int *array, int size)
{
	int	*sorted;
	int	i;

	if (!array || !size)
		return (SUCCESS);
	sorted = get_sorted_array(array, size);
	if (!sorted)
		return (ERROR);
	i = 0;
	while (i < size)
	{
		array[i] = ft_search_index(array[i], sorted, size);
		i++;
	}
	free(sorted);
	return (SUCCESS);
}

bool	is_sorted(t_stack *s)
{
	int	i;

	i = 1;
	while (i < s->size)
	{
		if (get_top_n(s, i) > get_top_n(s, i + 1))
			return (false);
		i++;
	}
	return (true);
}
