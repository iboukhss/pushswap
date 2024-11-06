/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:18:02 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/05 14:07:56 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	state_push_min(t_state *state, t_stack *stack)
{
	if (state->curr.pos == TOP_A)
	{
		push_b(stack);
		rotate_b(stack);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_a(stack);
		push_b(stack);
		rotate_b(stack);
	}
	else if (state->curr.pos == TOP_B)
	{
		rotate_b(stack);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_b(stack);
	}
	chunk_pop(state, state->curr.pos);
	chunk_push(state, state->min.pos);
}

void	state_push_mid(t_state *state, t_stack *stack)
{
	if (state->curr.pos == TOP_A)
	{
		push_b(stack);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_a(stack);
		push_b(stack);
	}
	else if (state->curr.pos == TOP_B)
	{
		push_a(stack);
		rotate_a(stack);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_b(stack);
		push_a(stack);
		rotate_a(stack);
	}
	chunk_pop(state, state->curr.pos);
	chunk_push(state, state->mid.pos);
}

void	state_push_max(t_state *state, t_stack *stack)
{
	if (state->curr.pos == TOP_A)
	{
		rotate_a(stack);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_a(stack);
	}
	else if (state->curr.pos == TOP_B)
	{
		push_a(stack);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_b(stack);
		push_a(stack);
	}
	chunk_pop(state, state->curr.pos);
	chunk_push(state, state->max.pos);
}
