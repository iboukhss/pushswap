/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:40:23 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 14:23:26 by iboukhss         ###   ########.fr       */
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
	else
	{
		printf("****** PROBLEM HERE ******\n");
	}
}

static void	split_chunks(t_state *state, t_stack *stack, t_sort *sort)
{
	printf("****** SPLIT CHUNKS ******\n");
	stack_print(stack);
	state_print(state);
	sort_print(sort);

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

	stack_print(stack);
	state_print(state);
}

static void	reinsert_max(t_state *state, t_stack *stack)
{
	printf("****** REINSERT MAX ******\n");
	while (state->max.len > 0)
	{
		state_pop_max(state, stack);
	}
	if (stack->len_a >= 2)
	{
		if (*stack->beg_a > *(stack->beg_a + 1))
		{
			swap_a(stack);
		}
	}
}

static void	reinsert_mid(t_state *state, t_stack *stack)
{
	printf("****** REINSERT MID ******\n");
	while (state->mid.len > 0)
	{
		state_pop_mid(state, stack);
	}
	if (stack->len_a >= 2)
	{
		if (*stack->beg_a > *(stack->beg_a + 1))
		{
			swap_a(stack);
		}
	}
}

static void	reinsert_min(t_state *state, t_stack *stack)
{
	printf("****** REINSERT MIN ******\n");
	while (state->min.len > 0)
	{
		state_pop_min(state, stack);
	}
	if (stack->len_a >= 2)
	{
		if (*stack->beg_a > *(stack->beg_a + 1))
		{
			swap_a(stack);
		}
	}
}

static void	qsort_recursive(t_stack *stack, t_state *state, t_sort *sort)
{
	t_state	new_state;
	t_sort	new_sort;

	split_chunks(state, stack, sort);
	if (state->max.len >= 3)
	{
		state_init(&new_state, stack, state->max.len, state->max.pos);
		find_pivots(&new_sort, &sort->arr[sort->qi + 1], state->max.len);
		qsort_recursive(stack, &new_state, &new_sort);
	}
	else
	{
		reinsert_max(state, stack);
	}
	if (state->mid.len >= 3)
	{
		state_init(&new_state, stack, state->mid.len, state->mid.pos);
		find_pivots(&new_sort, &sort->arr[sort->pi + 1], state->mid.len);
		qsort_recursive(stack, &new_state, &new_sort);
	}
	else
	{
		reinsert_mid(state, stack);
	}
	if (state->min.len >= 3)
	{
		state_init(&new_state, stack, state->min.len, state->min.pos);
		find_pivots(&new_sort, sort->arr, state->min.len);
		qsort_recursive(stack, &new_state, &new_sort);
	}
	else
	{
		reinsert_min(state, stack);
	}
}

void	stack_qsort(t_stack *stack, int *array, ptrdiff_t array_size)
{
	t_state	state;
	t_sort	sort;

	state_init(&state, stack, stack->cap, TOP_A);
	ft_quicksort(array, array_size);
	find_pivots(&sort, array, array_size);

	//stack_print(stack);

	qsort_recursive(stack, &state, &sort);

	//stack_print(stack);
	//state_print(&state);
	//sort_print(&sort);
}
