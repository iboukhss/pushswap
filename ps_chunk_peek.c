/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_chunk_peek.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 22:27:07 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/02 00:29:00 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

bool	chunk_is_empty(t_state *state, t_position pos)
{
	return (chunk_at(state, pos)->len == 0);
}

bool	chunk_is_full(t_state *state)
{
	ptrdiff_t	total_len;

	total_len = state->curr.len + state->min.len;
	total_len += state->mid.len + state->max.len;
	return (total_len == state->stack->cap);
}
