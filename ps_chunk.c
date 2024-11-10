/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:02:22 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 19:06:33 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

t_chunk	*chunk_at(t_state *state, t_position pos)
{
	if (state->curr.pos == pos)
	{
		return (&state->curr);
	}
	if (state->min.pos == pos)
	{
		return (&state->min);
	}
	if (state->mid.pos == pos)
	{
		return (&state->mid);
	}
	if (state->max.pos == pos)
	{
		return (&state->max);
	}
	return (NULL);
}

bool	chunk_is_empty(t_state *state, t_position pos)
{
	return (chunk_at(state, pos)->len == 0);
}

bool	chunk_is_full(t_state *state)
{
	ptrdiff_t	total_len;

	total_len = state->curr.len + state->min.len;
	total_len += state->mid.len + state->max.len;
	return (total_len == state->cap);
}

int	chunk_data(t_chunk chunk)
{
	if (chunk.pos == TOP_A || chunk.pos == TOP_B)
	{
		return (*(chunk.beg));
	}
	if (chunk.pos == BOT_A || chunk.pos == BOT_B)
	{
		return (*(chunk.end - 1));
	}
	return (-42);
}
