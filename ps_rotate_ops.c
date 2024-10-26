/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:56:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 03:02:46 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

void	rotate_a(t_stack *stack)
{
	int	val;
	int	err;

	err = stack_a_pop_front(&val, stack);
	if (!err)
	{
		stack_a_push_back(stack, val);
		puts("ra");
	}
}

void	rotate_b(t_stack *stack)
{
	int	val;
	int	err;

	err = stack_b_pop_front(&val, stack);
	if (!err)
	{
		stack_b_push_back(stack, val);
		puts("rb");
	}
}

void	reverse_rotate_a(t_stack *stack)
{
	int	val;
	int	err;

	err = stack_a_pop_back(&val, stack);
	if (!err)
	{
		stack_a_push_front(stack, val);
		puts("rra");
	}
}

void	reverse_rotate_b(t_stack *stack)
{
	int	val;
	int	err;

	err = stack_b_pop_back(&val, stack);
	if (!err)
	{
		stack_b_push_front(stack, val);
		puts("rrb");
	}
}
