/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:05:23 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/31 00:18:44 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

// NOTE: Another horror I need to refactor but I can't be bothered right now.
// This function could segfault potentially, it's pretty bad.

static void	pop_from_top_a(t_state *state, t_chunk *chunk)
{
	chunk->end -= 1;
	chunk->len -= 1;
	chunk_at(state, BOT_A)->beg -= 1;
	chunk_at(state, BOT_A)->end -= 1;
	chunk_at(state, TOP_B)->beg -= 1;
	chunk_at(state, TOP_B)->end -= 1;
	chunk_at(state, BOT_B)->beg -= 1;
	chunk_at(state, BOT_B)->end -= 1;
}

static void	pop_from_bot_a(t_state *state, t_chunk *chunk)
{
	chunk->end -= 1;
	chunk->len -= 1;
	chunk_at(state, TOP_B)->beg -= 1;
	chunk_at(state, TOP_B)->end -= 1;
	chunk_at(state, BOT_B)->beg -= 1;
	chunk_at(state, BOT_B)->end -= 1;
}

static void	pop_from_top_b(t_state *state, t_chunk *chunk)
{
	chunk->end -= 1;
	chunk->len -= 1;
	chunk_at(state, BOT_B)->beg -= 1;
	chunk_at(state, BOT_B)->end -= 1;
}

static void	pop_from_bot_b(t_state *state, t_chunk *chunk)
{
	(void)state;
	chunk->end -= 1;
	chunk->len -= 1;
}

void	chunk_pop(t_state *state, t_position pos)
{
	t_chunk	*chunk;

	chunk = chunk_at(state, pos);
	if (chunk_is_empty(chunk))
	{
		return ;
	}
	if (chunk->pos == TOP_A)
	{
		pop_from_top_a(state, chunk);
	}
	else if (chunk->pos == BOT_A)
	{
		pop_from_bot_a(state, chunk);
	}
	else if (chunk->pos == TOP_B)
	{
		pop_from_top_b(state, chunk);
	}
	else if (chunk->pos == BOT_B)
	{
		pop_from_bot_b(state, chunk);
	}
}
