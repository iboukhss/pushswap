/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:12:53 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/01 21:58:01 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <string.h>

int	stack_pop_back_a(t_stack *stack)
{
	ptrdiff_t	move_size;
	int			val;

	if (stack_is_empty_a(stack))
	{
		return (-42);
	}
	val = *(stack->end_a - 1);
	move_size = (stack->end_b - stack->end_a) * sizeof(*stack->data);
	memmove(stack->end_a - 1, stack->end_a, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_a -= 1;
	stack->beg_b -= 1;
	stack->end_b -= 1;
	return (val);
}

int	stack_pop_front_a(t_stack *stack)
{
	ptrdiff_t	move_size;
	int			val;

	if (stack_is_empty_a(stack))
	{
		return (-42);
	}
	val = *(stack->beg_a);
	move_size = (stack->end_b - stack->beg_a - 1) * sizeof(*stack->data);
	memmove(stack->beg_a, stack->beg_a + 1, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_a -= 1;
	stack->beg_b -= 1;
	stack->end_b -= 1;
	return (val);
}

int	stack_pop_back_b(t_stack *stack)
{
	int	val;

	if (stack_is_empty_b(stack))
	{
		return (-42);
	}
	val = *(stack->end_b - 1);
	*(stack->end_b - 1) = 0;
	stack->end_b -= 1;
	return (val);
}

int	stack_pop_front_b(t_stack *stack)
{
	ptrdiff_t	move_size;
	int			val;

	if (stack_is_empty_b(stack))
	{
		return (-42);
	}
	val = *(stack->beg_b);
	move_size = (stack->end_b - stack->beg_b - 1) * sizeof(*stack->data);
	memmove(stack->beg_b, stack->beg_b + 1, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_b -= 1;
	return (val);
}
