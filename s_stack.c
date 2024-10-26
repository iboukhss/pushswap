/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:47:20 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 01:17:35 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <stdlib.h>

t_stack	*stack_new(ptrdiff_t stack_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(stack_size * sizeof(int));
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->cap = stack_size;
	stack->beg_a = stack->data;
	stack->end_a = stack->data;
	stack->beg_b = stack->data;
	stack->end_b = stack->data;
	return (stack);
}

void	stack_delete(t_stack *stack)
{
	free(stack->data);
	free(stack);
}

bool	stack_is_full(t_stack *stack)
{
	return (stack->end_b - stack->beg_a == stack->cap);
}

bool	stack_a_is_empty(t_stack *stack)
{
	return (stack->end_a - stack->beg_a == 0);
}

bool	stack_b_is_empty(t_stack *stack)
{
	return (stack->end_b - stack->beg_b == 0);
}
