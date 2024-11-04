/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:12:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/03 21:52:36 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	state_pop_min(t_state *state)
{
	if (state->curr.pos == TOP_A)
	{
		reverse_rotate_b(state);
		push_a(state);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_b(state);
		push_a(state);
		rotate_a(state);
	}
	else if (state->curr.pos == TOP_B)
	{
		reverse_rotate_b(state);
	}
	else if (state->curr.pos == BOT_B)
	{
		rotate_b(state);
	}
	chunk_pop(state, state->min.pos);
	chunk_push(state, state->curr.pos);
}

void	state_pop_mid(t_state *state)
{
	if (state->curr.pos == TOP_A)
	{
		push_a(state);
	}
	else if (state->curr.pos == BOT_A)
	{
		push_a(state);
		rotate_a(state);
	}
	else if (state->curr.pos == TOP_B)
	{
		reverse_rotate_a(state);
		push_b(state);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_a(state);
		push_b(state);
		rotate_b(state);
	}
	chunk_pop(state, state->mid.pos);
	chunk_push(state, state->curr.pos);
}

void	state_pop_max(t_state *state)
{
	if (state->curr.pos == TOP_A)
	{
		reverse_rotate_a(state);
	}
	else if (state->curr.pos == BOT_A)
	{
		rotate_a(state);
	}
	else if (state->curr.pos == TOP_B)
	{
		push_b(state);
	}
	else if (state->curr.pos == BOT_B)
	{
		push_b(state);
		rotate_b(state);
	}
	chunk_pop(state, state->max.pos);
	chunk_push(state, state->curr.pos);
}
