/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:57:07 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/05 21:21:31 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

bool	stack_is_full(t_stack *stack)
{
	return (stack->len_a + stack->len_b == stack->cap);
}

bool	stack_is_empty_a(t_stack *stack)
{
	return (stack->len_a == 0);
}

bool	stack_is_empty_b(t_stack *stack)
{
	return (stack->len_b == 0);
}
