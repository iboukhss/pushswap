/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_state_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 14:12:57 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/31 19:14:53 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

void	state_pop_min(t_state *state)
{
	if (state->min.pos == TOP_B)
	{
		push_a(state);
	}
	else if (state->min.pos == BOT_B)
	{
		reverse_rotate_b(state);
		push_a(state);
	}
}

void	state_pop_mid(t_state *state)
{
	if (state->mid.pos == BOT_A)
	{
		reverse_rotate_a(state);
	}
	else if (state->mid.pos == TOP_B)
	{
		push_a(state);
	}
}

void	state_pop_max(t_state *state)
{
	if (state->max.pos == TOP_A)
	{
		rotate_a(state);
	}
	else if (state->max.pos == BOT_A)
	{
		reverse_rotate_a(state);
	}
}
