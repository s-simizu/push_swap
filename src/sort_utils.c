/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshimizu <sshimizu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 00:20:30 by sshimizu          #+#    #+#             */
/*   Updated: 2023/02/21 05:05:47 by sshimizu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <types.h>

static int	*sorted_array(int *array, int size)
{
	int	*sorted;

	if (!array || !size)
		return (NULL);
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
	int	sorted_index;
	int	array_index;

	sorted = sorted_array(array, size);
	if (!sorted)
		return (ERROR);
	array_index = 0;
	while (array_index < size)
	{
		sorted_index = 0;
		while (sorted_index < size)
		{
			if (array[array_index] == sorted[sorted_index])
			{
				array[array_index] = sorted_index;
				break ;
			}
			sorted_index++;
		}
		array_index++;
	}
	free(sorted);
	return (SUCCESS);
}

bool	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (false);
		i++;
	}
	return (true);
}
