/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:01:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 02:49:11 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include <stdio.h>

void	push_a(t_stack *stack)
{
	int	val;
	int	err;

	err = stack_b_pop_front(&val, stack);
	if (!err)
	{
		stack_a_push_front(stack, val);
		puts("pa");
	}
}

void	push_b(t_stack *stack)
{
	int	val;
	int	err;

	err = stack_a_pop_front(&val, stack);
	if (!err)
	{
		stack_b_push_front(stack, val);
		puts("pb");
	}
}
