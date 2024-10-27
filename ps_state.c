/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:09:07 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 15:23:07 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

// NOTE: Countless bugs happened here. It is not the best way to go about
// things but I don't know what else to do.

static void	init_from_top_a(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = TOP_A;
	state->min.pos = BOT_B;
	state->mid.pos = TOP_B;
	state->max.pos = BOT_A;
	state->curr.beg = stack->beg_a;
	state->curr.end = stack->beg_a + len;
	state->min.beg = stack->end_b;
	state->min.end = stack->end_b;
	state->mid.beg = stack->beg_b;
	state->mid.end = stack->beg_b;
	state->max.beg = stack->end_a;
	state->max.end = stack->end_a;
}

static void	init_from_bot_a(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = BOT_A;
	state->min.pos = BOT_B;
	state->mid.pos = TOP_B;
	state->max.pos = TOP_A;
	state->curr.beg = stack->end_a - len;
	state->curr.end = stack->end_a;
	state->min.beg = stack->end_b;
	state->min.end = stack->end_b;
	state->mid.beg = stack->beg_b;
	state->mid.end = stack->beg_b;
	state->max.beg = stack->beg_a;
	state->max.end = stack->beg_a;
}

static void	init_from_top_b(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = TOP_B;
	state->min.pos = BOT_B;
	state->mid.pos = BOT_A;
	state->max.pos = TOP_A;
	state->curr.beg = stack->beg_b;
	state->curr.end = stack->beg_b + len;
	state->min.beg = stack->end_b;
	state->min.end = stack->end_b;
	state->mid.beg = stack->end_a;
	state->mid.end = stack->end_a;
	state->max.beg = stack->beg_a;
	state->max.end = stack->beg_a;
}

static void	init_from_bot_b(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = BOT_B;
	state->min.pos = TOP_B;
	state->mid.pos = BOT_A;
	state->max.pos = TOP_A;
	state->curr.beg = stack->end_b - len;
	state->curr.end = stack->end_b;
	state->min.beg = stack->beg_b;
	state->min.end = stack->beg_b;
	state->mid.beg = stack->end_a;
	state->mid.end = stack->end_a;
	state->max.beg = stack->beg_a;
	state->max.end = stack->beg_a;
}

void	state_init(t_state *state, t_stack *stack, t_position pos, ptrdiff_t len)
{
	state->stack = stack;
	if (pos == TOP_A)
	{
		init_from_top_a(state, stack, len);
	}
	else if (pos == BOT_A)
	{
		init_from_bot_a(state, stack, len);
	}
	else if (pos == TOP_B)
	{
		init_from_top_b(state, stack, len);
	}
	else if (pos == BOT_B)
	{
		init_from_bot_b(state, stack, len);
	}
	else
	{
		return ;
	}
}
