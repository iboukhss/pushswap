/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:47:20 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/25 20:02:01 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <stdlib.h>

t_stack	*stack_new(ptrdiff_t stack_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!stack)
		return (NULL);
	stack->data = malloc(stack_size * sizeof(*stack->data));
	if (!stack->data)
	{
		free(stack);
		return (NULL);
	}
	stack->cap = stack_size;
	stack->top_a = -1;
	stack->bot_a = 0;
	stack->top_b = stack_size;
	stack->bot_b = stack_size - 1;
	return (stack);
}

void	stack_delete(t_stack *stack)
{
	free(stack->data);
	free(stack);
}
