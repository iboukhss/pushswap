/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:12:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 07:28:21 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	state_pop_max(t_state *state, t_stack *stack)
{
	if (state->max.pos == TOP_A)
	{
		;
	}
	else if (state->max.pos == BOT_A)
	{
		reverse_rotate_a(stack);
	}
	chunk_pop(state, state->max.pos);
	chunk_push(state, state->curr.pos);
}

void	state_pop_min(t_state *state, t_stack *stack)
{
	if (state->min.pos == TOP_B)
	{
		push_a(stack);
	}
	else if (state->min.pos == BOT_B)
	{
		reverse_rotate_b(stack);
		push_a(stack);
	}
	chunk_pop(state, state->min.pos);
	chunk_push(state, state->curr.pos);
}

void	state_pop_mid(t_state *state, t_stack *stack)
{
	if (state->mid.pos == TOP_B)
	{
		push_a(stack);
	}
	else if (state->mid.pos == BOT_A)
	{
		reverse_rotate_a(stack);
	}
	chunk_pop(state, state->mid.pos);
	chunk_push(state, state->curr.pos);
}
