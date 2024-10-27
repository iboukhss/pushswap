/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:12:53 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 19:46:27 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <stdio.h>
#include <string.h>

// NOTE: Very messy, handcrafted operations. When writing this performance was
// not a concern. Readability could be improved.

int	stack_pop_back_a(int *out_val, t_stack *stack)
{
	ptrdiff_t	move_size;

	if (stack_is_empty_a(stack))
	{
		return (1);
	}
	if (out_val != NULL)
	{
		*out_val = *(stack->end_a - 1);
	}
	move_size = (stack->end_b - stack->end_a) * sizeof(*stack->data);
	memmove(stack->end_a - 1, stack->end_a, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_a -= 1;
	stack->beg_b -= 1;
	stack->end_b -= 1;
	return (0);
}

int	stack_pop_front_a(int *out_val, t_stack *stack)
{
	ptrdiff_t	move_size;

	if (stack_is_empty_a(stack))
	{
		return (1);
	}
	if (out_val != NULL)
	{
		*out_val = *(stack->beg_a);
	}
	move_size = (stack->end_b - stack->beg_a - 1) * sizeof(*stack->data);
	memmove(stack->beg_a, stack->beg_a + 1, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_a -= 1;
	stack->beg_b -= 1;
	stack->end_b -= 1;
	return (0);
}

int	stack_pop_back_b(int *out_val, t_stack *stack)
{
	if (stack_is_empty_b(stack))
	{
		return (1);
	}
	if (out_val != NULL)
	{
		*out_val = *(stack->end_b - 1);
	}
	*(stack->end_b - 1) = 0;
	stack->end_b -= 1;
	return (0);
}

int	stack_pop_front_b(int *out_val, t_stack *stack)
{
	ptrdiff_t	move_size;

	if (stack_is_empty_b(stack))
	{
		return (1);
	}
	if (out_val != NULL)
	{
		*out_val = *(stack->beg_b);
	}
	move_size = (stack->end_b - stack->beg_b - 1) * sizeof(*stack->data);
	memmove(stack->beg_b, stack->beg_b + 1, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_b -= 1;
	return (0);
}
