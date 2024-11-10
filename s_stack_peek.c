/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:01:36 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/09 21:03:37 by iboukhss         ###   ########.fr       */
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
