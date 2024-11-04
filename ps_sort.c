/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:23 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/04 01:59:32 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"
#include "dbg_main.h"

#include <stdio.h>

static void	find_pivots(t_sort *sort, int *array, ptrdiff_t array_size)
{
	ptrdiff_t	third;

	if (array_size >= 3)
	{
		third = array_size / 3;
		sort->arr = array;
		sort->size = array_size;
		sort->pi = third - 1;
		sort->qi = third + third - 1;
		sort->p = array[sort->pi];
		sort->q = array[sort->qi];
	}
	else
	{
		printf("*** PROBLEM HERE *** PROBLEM HERE *** PROBLEM HERE ***\n");
	}
}

static void	qsort_recursive(t_state *state, t_sort *sort)
{
	t_state	new_state;
	t_sort	new_sort;

	stack_print(state->stack);
	state_print(state);
	sort_print(sort);

	while (state->curr.len > 0)
	{
		if (chunk_data(state->curr) <= sort->p)
		{
			state_push_min(state);
		}
		else if (chunk_data(state->curr) <= sort->q)
		{
			state_push_mid(state);
		}
		else
		{
			state_push_max(state);
		}
	}

	// Max chunk
	if (state->max.len >= 3)
	{
		printf("****** MAX CHUNK *** MAX CHUNK *** MAX CHUNK ******\n");
		state_init(&new_state, state->stack, state->max.pos, state->max.len);
		find_pivots(&new_sort, &sort->arr[sort->qi + 1], state->max.len);
		qsort_recursive(&new_state, &new_sort);
	}

	// Mid chunk
	if (state->mid.len >= 3)
	{
		printf("****** MID CHUNK *** MID CHUNK *** MID CHUNK ******\n");
		state_init(&new_state, state->stack, state->mid.pos, state->mid.len);
		find_pivots(&new_sort, &sort->arr[sort->pi + 1], state->mid.len);
		qsort_recursive(&new_state, &new_sort);
	}

	// Min chunk
	if (state->min.len >= 3)
	{
		printf("****** MIN CHUNK *** MIN CHUNK *** MIN CHUNK ******\n");
		state_init(&new_state, state->stack, state->min.pos, state->min.len);
		find_pivots(&new_sort, sort->arr, state->min.len);
		qsort_recursive(&new_state, &new_sort);
	}

	printf("****** SIMPLE SORTING ******\n");
	stack_print(state->stack);
	state_print(state);

	if (state->curr.pos == TOP_A || state->curr.pos == BOT_A)
	{
		while (state->max.len > 0)
		{
			state_pop_max(state);
		}
		while (state->mid.len > 0)
		{
			state_pop_mid(state);
		}
		while (state->min.len > 0)
		{
			state_pop_min(state);
		}
	}

	else if (state->curr.pos == TOP_B || state->curr.pos == BOT_B)
	{
		while (state->min.len > 0)
		{
			state_pop_min(state);
		}
		while (state->mid.len > 0)
		{
			state_pop_mid(state);
		}
		while (state->max.len > 0)
		{
			state_pop_max(state);
		}
	}

	stack_print(state->stack);
	state_print(state);
}

void	stack_qsort(t_stack *stack, int *array, ptrdiff_t array_size)
{
	t_state	state;
	t_sort	sort;

	state_init(&state, stack, TOP_A, stack->cap);
	ft_quicksort(array, array_size);
	find_pivots(&sort, array, array_size);
	qsort_recursive(&state, &sort);

	stack_print(stack);
	state_print(&state);
	sort_print(&sort);
}
