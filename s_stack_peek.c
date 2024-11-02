/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:57:07 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/01 21:59:23 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

bool	stack_is_full(t_stack *stack)
{
	return (stack->end_b - stack->beg_a == stack->cap);
}

bool	stack_is_empty_a(t_stack *stack)
{
	return (stack->end_a - stack->beg_a == 0);
}

bool	stack_is_empty_b(t_stack *stack)
{
	return (stack->end_b - stack->beg_b == 0);
}
