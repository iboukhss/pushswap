/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:15:38 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/02 00:32:54 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

static void	push_to_top_a(t_state *state)
{
	chunk_at(state, TOP_A)->end += 1;
	chunk_at(state, TOP_A)->len += 1;
	chunk_at(state, BOT_A)->beg += 1;
	chunk_at(state, BOT_A)->end += 1;
	chunk_at(state, TOP_B)->beg += 1;
	chunk_at(state, TOP_B)->end += 1;
	chunk_at(state, BOT_B)->beg += 1;
	chunk_at(state, BOT_B)->end += 1;
}

static void	push_to_bot_a(t_state *state)
{
	chunk_at(state, BOT_A)->end += 1;
	chunk_at(state, BOT_A)->len += 1;
	chunk_at(state, TOP_B)->beg += 1;
	chunk_at(state, TOP_B)->end += 1;
	chunk_at(state, BOT_B)->beg += 1;
	chunk_at(state, BOT_B)->end += 1;
}

static void	push_to_top_b(t_state *state)
{
	chunk_at(state, TOP_B)->end += 1;
	chunk_at(state, TOP_B)->len += 1;
	chunk_at(state, BOT_B)->beg += 1;
	chunk_at(state, BOT_B)->end += 1;
}

static void	push_to_bot_b(t_state *state)
{
	chunk_at(state, BOT_B)->end += 1;
	chunk_at(state, BOT_B)->len += 1;
}

void	chunk_push(t_state *state, t_position pos)
{
	if (chunk_is_full(state))
	{
		return ;
	}
	if (pos == TOP_A)
	{
		push_to_top_a(state);
	}
	else if (pos == BOT_A)
	{
		push_to_bot_a(state);
	}
	else if (pos == TOP_B)
	{
		push_to_top_b(state);
	}
	else if (pos == BOT_B)
	{
		push_to_bot_b(state);
	}
}
