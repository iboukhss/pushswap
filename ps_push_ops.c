/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:01:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 15:39:22 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

// NOTE: Error checking could be improved.

void	push_a(t_state *state)
{
	int	val;
	int	err;

	err = stack_b_pop_front(&val, state->stack);
	if (!err)
	{
		chunk_pop(state, TOP_B);
		stack_a_push_front(state->stack, val);
		chunk_push(state, TOP_A);
		puts("pa");
	}
}

void	push_b(t_state *state)
{
	int	val;
	int	err;

	err = stack_a_pop_front(&val, state->stack);
	if (!err)
	{
		chunk_pop(state, TOP_A);
		stack_b_push_front(state->stack, val);
		chunk_push(state, TOP_B);
		puts("pb");
	}
}
