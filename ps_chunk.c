/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:02:22 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 18:35:07 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

// NOTE: Failcase helped finding bugs.
t_chunk	*chunk_at(t_state *state, t_position pos)
{
	if (state->curr.pos == pos)
	{
		return (&state->curr);
	}
	else if (state->min.pos == pos)
	{
		return (&state->min);
	}
	else if (state->mid.pos == pos)
	{
		return (&state->mid);
	}
	else if (state->max.pos == pos)
	{
		return (&state->max);
	}
	else
	{
		return (NULL);
	}
}

bool	chunk_is_empty(t_chunk *chunk)
{
	return (chunk->end - chunk->beg == 0);
}

int	chunk_peek(t_chunk *chunk)
{
	if (chunk->pos == TOP_A || chunk->pos == TOP_B)
	{
		return (*chunk->beg);
	}
	else
	{
		return (*(chunk->end - 1));
	}
}
