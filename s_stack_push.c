/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:12:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 12:30:10 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include "string.h"

void	stack_a_push_back(t_stack *stack, int value)
{
	ptrdiff_t	move_size;

	if (stack_is_full(stack))
	{
		return ;
	}
	move_size = (stack->end_b - stack->beg_b) * sizeof(*stack->data);
	memmove(stack->beg_b + 1, stack->beg_b, move_size);
	*(stack->end_a) = value;
	stack->end_a += 1;
	stack->beg_b += 1;
	stack->end_b += 1;
}

void	stack_a_push_front(t_stack *stack, int value)
{
	ptrdiff_t	move_size;

	if (stack_is_full(stack))
	{
		return ;
	}
	move_size = (stack->end_b - stack->beg_a) * sizeof(*stack->data);
	memmove(stack->beg_a + 1, stack->beg_a, move_size);
	*(stack->beg_a) = value;
	stack->end_a += 1;
	stack->beg_b += 1;
	stack->end_b += 1;
}

void	stack_b_push_back(t_stack *stack, int value)
{
	if (stack_is_full(stack))
	{
		return ;
	}
	*(stack->end_b) = value;
	stack->end_b += 1;
}

void	stack_b_push_front(t_stack *stack, int value)
{
	ptrdiff_t	move_size;

	if (stack_is_full(stack))
	{
		return ;
	}
	move_size = (stack->end_b - stack->beg_b) * sizeof(*stack->data);
	memmove(stack->beg_b + 1, stack->beg_b, move_size);
	*(stack->beg_b) = value;
	stack->end_b += 1;
}
