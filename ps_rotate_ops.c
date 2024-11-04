/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:56:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/03 21:48:16 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

void	rotate_a(t_state *state)
{
	int	val;

	val = stack_pop_front_a(state->stack);
	stack_push_back_a(state->stack, val);
	puts("ra");
}

void	rotate_b(t_state *state)
{
	int	val;

	val = stack_pop_front_b(state->stack);
	stack_push_back_b(state->stack, val);
	puts("rb");
}

void	reverse_rotate_a(t_state *state)
{
	int	val;

	val = stack_pop_back_a(state->stack);
	stack_push_front_a(state->stack, val);
	puts("rra");
}

void	reverse_rotate_b(t_state *state)
{
	int	val;

	val = stack_pop_back_b(state->stack);
	stack_push_front_b(state->stack, val);
	puts("rrb");
}
