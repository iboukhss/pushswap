/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:02:04 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 19:03:32 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

static void	reinsert_max(t_state *state, t_stack *stack)
{
	while (state->max.len > 0)
	{
		state_pop_max(state, stack);
	}
	if (stack->len_a >= 2)
	{
		sort_two(stack);
	}
}

static void	reinsert_mid(t_state *state, t_stack *stack)
{
	while (state->mid.len > 0)
	{
		state_pop_mid(state, stack);
	}
	if (stack->len_a >= 2)
	{
		sort_two(stack);
	}
}

static void	reinsert_min(t_state *state, t_stack *stack)
{
	while (state->min.len > 0)
	{
		state_pop_min(state, stack);
	}
	if (stack->len_a >= 2)
	{
		sort_two(stack);
	}
}

void	sort_two(t_stack *stack)
{
	int	a;
	int	b;

	if (stack->len_a >= 2)
	{
		a = *(stack->beg_a);
		b = *(stack->beg_a + 1);
		if (a > b)
		{
			swap_a(stack);
		}
	}
}

void	sort_small(t_state *state, t_stack *stack)
{
	if (state->max.len <= 2)
	{
		reinsert_max(state, stack);
	}
	if (state->mid.len <= 2)
	{
		reinsert_mid(state, stack);
	}
	if (state->min.len <= 2)
	{
		reinsert_min(state, stack);
	}
}
