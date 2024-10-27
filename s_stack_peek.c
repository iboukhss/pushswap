/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:57:07 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 19:39:42 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

// NOTE: These functions should always be guarded when used, I am purposefully
// letting them segfault in case an error happens to help debugging.

int	stack_front_a(t_stack *stack)
{
	return (*stack->beg_a);
}

int	stack_front_b(t_stack *stack)
{
	return (*stack->beg_b);
}
