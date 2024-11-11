/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:23 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 19:05:58 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"
#include "libft.h"

static void	find_pivots(t_sort *sort, int *array, ptrdiff_t array_size)
{
	ptrdiff_t	third;

	if (array_size >= 3)
	{
		third = array_size / 3;
		sort->arr = array;
		sort->size = array_size;
		if (array_size % 3 == 0 || array_size % 3 == 1)
		{
			sort->pi = third - 1;
			sort->qi = third + third - 1;
		}
		else if (array_size % 3 == 2)
		{
			sort->pi = third;
			sort->qi = third + third;
		}
		sort->p = array[sort->pi];
		sort->q = array[sort->qi];
	}
}

static void	split_chunks(t_state *state, t_stack *stack, t_sort *sort)
{
	while (state->curr.len > 0)
	{
		if (chunk_data(state->curr) <= sort->p)
		{
			state_push_min(state, stack);
		}
		else if (chunk_data(state->curr) <= sort->q)
		{
			state_push_mid(state, stack);
		}
		else
		{
			state_push_max(state, stack);
		}
	}
}

static void	sort_large_recursive(t_stack *stack, t_state *state, t_sort *sort)
{
	t_state	new_state;
	t_sort	new_sort;

	if (state->max.len >= 3)
	{
		state_init(&new_state, stack, state->max.len, state->max.pos);
		find_pivots(&new_sort, &sort->arr[sort->qi + 1], state->max.len);
		qsort_recursive(stack, &new_state, &new_sort);
	}
	if (state->mid.len >= 3)
	{
		state_init(&new_state, stack, state->mid.len, state->mid.pos);
		find_pivots(&new_sort, &sort->arr[sort->pi + 1], state->mid.len);
		qsort_recursive(stack, &new_state, &new_sort);
	}
	if (state->min.len >= 3)
	{
		state_init(&new_state, stack, state->min.len, state->min.pos);
		find_pivots(&new_sort, sort->arr, state->min.len);
		qsort_recursive(stack, &new_state, &new_sort);
	}
}

void	qsort_recursive(t_stack *stack, t_state *state, t_sort *sort)
{
	if (state->curr.len <= 2)
	{
		sort_two(stack);
		return ;
	}
	split_chunks(state, stack, sort);
	sort_small(state, stack);
	sort_large_recursive(stack, state, sort);
}

void	stack_qsort(t_stack *stack, int *array, ptrdiff_t array_size)
{
	t_state	state;
	t_sort	sort;

	state_init(&state, stack, stack->cap, TOP_A);
	ft_quicksort(array, array_size);
	find_pivots(&sort, array, array_size);
	qsort_recursive(stack, &state, &sort);
}
