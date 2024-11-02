/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 19:18:02 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/01 17:37:13 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	state_push_min(t_state *state)
{
	if (state->curr.pos == TOP_A)
	{
		push_b(state);
		rotate_b(state);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_a(state);
		push_b(state);
		rotate_b(state);
	}
	else if (state->curr.pos == TOP_B)
	{
		rotate_b(state);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_b(state);
	}
}

void	state_push_mid(t_state *state)
{
	if (state->curr.pos == TOP_A)
	{
		push_b(state);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_a(state);
		push_b(state);
	}
	else if (state->curr.pos == TOP_B)
	{
		push_a(state);
		rotate_a(state);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_b(state);
		push_a(state);
		rotate_a(state);
	}
}

void	state_push_max(t_state *state)
{
	if (state->curr.pos == TOP_A)
	{
		rotate_a(state);
	}
	else if (state->curr.pos == BOT_A)
	{
		reverse_rotate_a(state);
	}
	else if (state->curr.pos == TOP_B)
	{
		push_a(state);
	}
	else if (state->curr.pos == BOT_B)
	{
		reverse_rotate_b(state);
		push_a(state);
	}
}
