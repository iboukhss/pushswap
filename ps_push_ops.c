/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:01:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 11:24:58 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

// NOTE: Error checking could be improved.

void	push_a(t_state *state)
{
	int		val;
	int		err;
	t_chunk	*src;
	t_chunk	*dst;

	src = chunk_at(state, TOP_B);
	dst = chunk_at(state, TOP_A);
	err = stack_b_pop_front(&val, state->stack);
	if (!err)
	{
		stack_a_push_front(state->stack, val);
		src->beg += 1;
		dst->end += 1;
		puts("pa");
	}
}

void	push_b(t_state *state)
{
	int		val;
	int		err;
	t_chunk	*src;
	t_chunk	*dst;

	src = chunk_at(state, TOP_A);
	dst = chunk_at(state, TOP_B);
	err = stack_a_pop_front(&val, state->stack);
	if (!err)
	{
		stack_b_push_front(state->stack, val);
		src->end -= 1;
		dst->beg -= 1;
		puts("pb");
	}
}
