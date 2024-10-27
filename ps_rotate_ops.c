/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:56:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 11:28:22 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

void	rotate_a(t_state *state)
{
	int		val;
	int		err;
	t_chunk	*src;
	t_chunk	*dst;

	src = chunk_at(state, TOP_A);
	dst = chunk_at(state, BOT_A);
	err = stack_a_pop_front(&val, state->stack);
	if (!err)
	{
		stack_a_push_back(state->stack, val);
		src->end -= 1;
		dst->beg -= 1;
		puts("ra");
	}
}

void	rotate_b(t_state *state)
{
	int		val;
	int		err;
	t_chunk	*src;
	t_chunk	*dst;

	src = chunk_at(state, TOP_B);
	dst = chunk_at(state, BOT_B);
	err = stack_b_pop_front(&val, state->stack);
	if (!err)
	{
		stack_b_push_back(state->stack, val);
		src->end -= 1;
		dst->beg -= 1;
		puts("rb");
	}
}

void	reverse_rotate_a(t_state *state)
{
	int		val;
	int		err;
	t_chunk	*src;
	t_chunk	*dst;

	src = chunk_at(state, BOT_A);
	dst = chunk_at(state, TOP_A);
	err = stack_a_pop_back(&val, state->stack);
	if (!err)
	{
		stack_a_push_front(state->stack, val);
		src->beg += 1;
		dst->end += 1;
		puts("rra");
	}
}

void	reverse_rotate_b(t_state *state)
{
	int		val;
	int		err;
	t_chunk	*src;
	t_chunk	*dst;

	src = chunk_at(state, BOT_A);
	dst = chunk_at(state, TOP_A);
	err = stack_b_pop_back(&val, state->stack);
	if (!err)
	{
		stack_b_push_front(state->stack, val);
		src->beg += 1;
		dst->end += 1;
		puts("rrb");
	}
}
