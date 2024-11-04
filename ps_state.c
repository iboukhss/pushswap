/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:09:07 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/04 00:37:11 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

static void	init_from_top_a(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = TOP_A;
	state->curr.beg = stack->beg_a;
	state->curr.end = stack->beg_a + len;
	state->curr.len = len;
	state->min.pos = BOT_B;
	state->min.beg = stack->end_b;
	state->min.end = stack->end_b;
	state->min.len = 0;
	state->mid.pos = TOP_B;
	state->mid.beg = stack->beg_b;
	state->mid.end = stack->beg_b;
	state->mid.len = 0;
	state->max.pos = BOT_A;
	state->max.beg = stack->end_a;
	state->max.end = stack->end_a;
	state->max.len = 0;
}

static void	init_from_bot_a(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = BOT_A;
	state->curr.beg = stack->end_a - len;
	state->curr.end = stack->end_a;
	state->curr.len = len;
	state->max.pos = TOP_A;
	state->max.beg = stack->beg_a;
	state->max.end = stack->beg_a;
	state->max.len = 0;
	state->min.pos = BOT_B;
	state->min.beg = stack->end_b;
	state->min.end = stack->end_b;
	state->min.len = 0;
	state->mid.pos = TOP_B;
	state->mid.beg = stack->beg_b;
	state->mid.end = stack->beg_b;
	state->mid.len = 0;
}

static void	init_from_top_b(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = TOP_B;
	state->curr.beg = stack->beg_b;
	state->curr.end = stack->beg_b + len;
	state->curr.len = len;
	state->min.pos = BOT_B;
	state->min.beg = stack->end_b;
	state->min.end = stack->end_b;
	state->min.len = 0;
	state->mid.pos = BOT_A;
	state->mid.beg = stack->end_a;
	state->mid.end = stack->end_a;
	state->mid.len = 0;
	state->max.pos = TOP_A;
	state->max.beg = stack->beg_a;
	state->max.end = stack->beg_a;
	state->max.len = 0;
}

static void	init_from_bot_b(t_state *state, t_stack *stack, ptrdiff_t len)
{
	state->curr.pos = BOT_B;
	state->curr.beg = stack->end_b - len;
	state->curr.end = stack->end_b;
	state->curr.len = len;
	state->min.pos = TOP_B;
	state->min.beg = stack->beg_b;
	state->min.end = stack->beg_b;
	state->min.len = 0;
	state->mid.pos = BOT_A;
	state->mid.beg = stack->end_a;
	state->mid.end = stack->end_a;
	state->mid.len = 0;
	state->max.pos = TOP_A;
	state->max.beg = stack->beg_a;
	state->max.end = stack->beg_a;
	state->max.len = 0;
}

void	state_init(t_state *state, t_stack *stack, t_position pos,
			ptrdiff_t len)
{
	ptrdiff_t	len_a;
	ptrdiff_t	len_b;

	state->stack = stack;
	len_a = stack->end_a - stack->beg_a;
	len_b = stack->end_b - stack->beg_b;
	if (pos == TOP_A || (pos == BOT_A && len == len_a))
	{
		init_from_top_a(state, stack, len);
	}
	else if (pos == BOT_A)
	{
		init_from_bot_a(state, stack, len);
	}
	else if (pos == TOP_B || (pos == BOT_B && len == len_b))
	{
		init_from_top_b(state, stack, len);
	}
	else if (pos == BOT_B)
	{
		init_from_bot_b(state, stack, len);
	}
}
