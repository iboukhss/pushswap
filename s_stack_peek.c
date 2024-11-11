/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:01:36 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/11 14:47:38 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

int	stack_front_a(t_stack *stack)
{
	return (*stack->beg_a);
}

int	stack_front_b(t_stack *stack)
{
	return (*stack->beg_b);
}

int	stack_back_a(t_stack *stack)
{
	return (*(stack->end_a - 1));
}

int	stack_back_b(t_stack *stack)
{
	return (*(stack->end_b - 1));
}

bool	stack_is_sorted_a(t_stack *stack)
{
	ptrdiff_t	i;

	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->beg_a[i] > stack->beg_a[i + 1])
		{
			return (false);
		}
		i++;
	}
	return (true);
}
