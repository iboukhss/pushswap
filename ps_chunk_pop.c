/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:05:23 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/01 22:26:18 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

static void	pop_from_top_a(t_state *state)
{
	chunk_at(state, TOP_A)->end -= 1;
	chunk_at(state, TOP_A)->len -= 1;
	chunk_at(state, BOT_A)->beg -= 1;
	chunk_at(state, BOT_A)->end -= 1;
	chunk_at(state, TOP_B)->beg -= 1;
	chunk_at(state, TOP_B)->end -= 1;
	chunk_at(state, BOT_B)->beg -= 1;
	chunk_at(state, BOT_B)->end -= 1;
}

static void	pop_from_bot_a(t_state *state)
{
	chunk_at(state, BOT_A)->end -= 1;
	chunk_at(state, BOT_A)->len -= 1;
	chunk_at(state, TOP_B)->beg -= 1;
	chunk_at(state, TOP_B)->end -= 1;
	chunk_at(state, BOT_B)->beg -= 1;
	chunk_at(state, BOT_B)->end -= 1;
}

static void	pop_from_top_b(t_state *state)
{
	chunk_at(state, TOP_B)->end -= 1;
	chunk_at(state, TOP_B)->len -= 1;
	chunk_at(state, BOT_B)->beg -= 1;
	chunk_at(state, BOT_B)->end -= 1;
}

static void	pop_from_bot_b(t_state *state)
{
	chunk_at(state, BOT_B)->end -= 1;
	chunk_at(state, BOT_B)->len -= 1;
}

void	chunk_pop(t_state *state, t_position pos)
{
	if (chunk_is_empty(state, pos))
	{
		return ;
	}
	if (pos == TOP_A)
	{
		pop_from_top_a(state);
	}
	else if (pos == BOT_A)
	{
		pop_from_bot_a(state);
	}
	else if (pos == TOP_B)
	{
		pop_from_top_b(state);
	}
	else if (pos == BOT_B)
	{
		pop_from_bot_b(state);
	}
}
