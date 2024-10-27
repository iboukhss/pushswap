/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:56:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 17:31:27 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

void	rotate_a(t_state *state)
{
	int	val;
	int	err;

	err = stack_a_pop_front(&val, state->stack);
	if (!err)
	{
		chunk_pop(state, TOP_A);
		stack_a_push_back(state->stack, val);
		chunk_push(state, BOT_A);
		puts("ra");
	}
}

void	rotate_b(t_state *state)
{
	int	val;
	int	err;

	err = stack_b_pop_front(&val, state->stack);
	if (!err)
	{
		chunk_pop(state, TOP_B);
		stack_b_push_back(state->stack, val);
		chunk_push(state, BOT_B);
		puts("rb");
	}
}

void	reverse_rotate_a(t_state *state)
{
	int	val;
	int	err;

	err = stack_a_pop_back(&val, state->stack);
	if (!err)
	{
		chunk_pop(state, BOT_A);
		stack_a_push_front(state->stack, val);
		chunk_push(state, TOP_A);
		puts("rra");
	}
}

void	reverse_rotate_b(t_state *state)
{
	int	val;
	int	err;

	err = stack_b_pop_back(&val, state->stack);
	if (!err)
	{
		chunk_pop(state, BOT_B);
		stack_b_push_front(state->stack, val);
		chunk_push(state, TOP_B);
		puts("rrb");
	}
}
