/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:01:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/01 22:00:23 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

void	push_a(t_state *state)
{
	int	val;

	val = stack_pop_front_b(state->stack);
	stack_push_front_a(state->stack, val);
	chunk_pop(state, TOP_B);
	chunk_push(state, TOP_A);
	puts("pa");
}

void	push_b(t_state *state)
{
	int	val;

	val = stack_pop_front_a(state->stack);
	stack_push_front_b(state->stack, val);
	chunk_pop(state, TOP_A);
	chunk_push(state, TOP_B);
	puts("pb");
}
