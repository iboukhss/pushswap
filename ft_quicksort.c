/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 21:46:44 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 19:32:07 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// NOTE: Picking last index as pivot is a classic choice for quicksort.
static ptrdiff_t	partition(int *array, ptrdiff_t low, ptrdiff_t high)
{
	int			p;
	ptrdiff_t	i;
	ptrdiff_t	j;

	p = array[high];
	i = low - 1;
	j = low;
	while (j < high)
	{
		if (array[j] <= p)
		{
			++i;
			swap(&array[i], &array[j]);
		}
		++j;
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

static void	quicksort_recursive(int *array, ptrdiff_t low, ptrdiff_t high)
{
	ptrdiff_t	pi;

	if (low >= high)
	{
		return ;
	}
	pi = partition(array, low, high);
	quicksort_recursive(array, low, pi - 1);
	quicksort_recursive(array, pi + 1, high);
}

// NOTE: We pass the min and max indices to our recursive function.
void	ft_quicksort(int *array, ptrdiff_t array_size)
{
	quicksort_recursive(array, 0, array_size - 1);
}
