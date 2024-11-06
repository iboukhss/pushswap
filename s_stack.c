/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:47:20 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/05 22:58:04 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include <stdlib.h>
#include <string.h>

t_stack	*stack_new(int *array, ptrdiff_t array_size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (stack == NULL)
	{
		return (NULL);
	}
	stack->data = malloc(array_size * sizeof(*stack->data));
	if (stack->data == NULL)
	{
		free(stack);
		return (NULL);
	}
	memcpy(stack->data, array, array_size * sizeof(*stack->data));
	stack->beg_a = stack->data;
	stack->end_a = stack->beg_a + array_size;
	stack->beg_b = stack->end_a;
	stack->end_b = stack->beg_b + 0;
	stack->len_a = stack->end_a - stack->beg_a;
	stack->len_b = stack->end_b - stack->beg_b;
	stack->cap = array_size;
	return (stack);
}

void	stack_delete(t_stack *stack)
{
	free(stack->data);
	free(stack);
}
