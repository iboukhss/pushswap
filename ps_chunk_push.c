/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:38 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 15:43:06 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

static void	push_to_top_a(t_state *state, t_chunk *chunk)
{
	chunk->end += 1;
	chunk_at(state, BOT_A)->beg += 1;
	chunk_at(state, BOT_A)->end += 1;
	chunk_at(state, TOP_B)->beg += 1;
	chunk_at(state, TOP_B)->end += 1;
	chunk_at(state, BOT_B)->beg += 1;
	chunk_at(state, BOT_B)->end += 1;
}

static void	push_to_bot_a(t_state *state, t_chunk *chunk)
{
	chunk->end += 1;
	chunk_at(state, TOP_B)->beg += 1;
	chunk_at(state, TOP_B)->end += 1;
	chunk_at(state, BOT_B)->beg += 1;
	chunk_at(state, BOT_B)->end += 1;
}

static void	push_to_top_b(t_state *state, t_chunk *chunk)
{
	chunk->end += 1;
	chunk_at(state, BOT_B)->beg += 1;
	chunk_at(state, BOT_B)->end += 1;
}

static void	push_to_bot_b(t_state *state, t_chunk *chunk)
{
	(void)state;
	chunk->end += 1;
}

void	chunk_push(t_state *state, t_position pos)
{
	t_chunk	*chunk;

	chunk = chunk_at(state, pos);
	if (chunk->pos == TOP_A)
	{
		push_to_top_a(state, chunk);
	}
	else if (chunk->pos == BOT_A)
	{
		push_to_bot_a(state, chunk);
	}
	else if (chunk->pos == TOP_B)
	{
		push_to_top_b(state, chunk);
	}
	else if (chunk->pos == BOT_B)
	{
		push_to_bot_b(state, chunk);
	}
	else
	{
		return ;
	}
}
