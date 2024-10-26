/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:18:02 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 23:00:09 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	state_push_min(t_state *state)
{
	t_position	pos;
	t_stack		*stack;

	pos = state->curr.pos;
	stack = state->stack;
	if (pos == TOP_A)
	{
		push_b(stack);
		rotate_b(stack);
	}
	else if (pos == BOT_A)
	{
		reverse_rotate_a(stack);
		push_b(stack);
		rotate_b(stack);
	}
	else if (pos == TOP_B)
	{
		rotate_b(stack);
	}
	else if (pos == BOT_B)
	{
		reverse_rotate_b(stack);
	}
	state->curr.end -= 1;
	state->min.beg -= 1;
}

void	state_push_mid(t_state *state)
{
	t_position	pos;
	t_stack		*stack;

	pos = state->curr.pos;
	stack = state->stack;
	if (pos == TOP_A)
	{
		push_b(stack);
	}
	else if (pos == BOT_A)
	{
		reverse_rotate_a(stack);
		push_b(stack);
	}
	else if (pos == TOP_B)
	{
		push_a(stack);
		rotate_a(stack);
	}
	else if (pos == BOT_B)
	{
		reverse_rotate_b(stack);
		push_a(stack);
		rotate_a(stack);
	}
	state->curr.end -= 1;
	state->mid.beg -= 1;
}

void	state_push_max(t_state *state)
{
	t_position	pos;
	t_stack		*stack;

	pos = state->curr.pos;
	stack = state->stack;
	if (pos == TOP_A)
	{
		rotate_a(stack);
	}
	else if (pos == BOT_A)
	{
		reverse_rotate_a(stack);
	}
	else if (pos == TOP_B)
	{
		push_a(stack);
	}
	else if (pos == BOT_B)
	{
		reverse_rotate_b(stack);
		push_a(stack);
	}
	state->curr.end -= 1;
	state->max.beg -= 1;
}
