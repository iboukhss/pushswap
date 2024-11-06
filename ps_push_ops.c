/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:01:48 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 14:51:52 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include "libft.h"

void	push_a(t_stack *stack)
{
	int	val;

	val = stack_pop_front_b(stack);
	stack_push_front_a(stack, val);
	ft_puts("pa");
}

void	push_b(t_stack *stack)
{
	int	val;

	val = stack_pop_front_a(stack);
	stack_push_front_b(stack, val);
	ft_puts("pb");
}

void	swap_a(t_stack *stack)
{
	int	val_a;
	int	val_b;

	val_a = stack_pop_front_a(stack);
	val_b = stack_pop_front_a(stack);
	stack_push_front_a(stack, val_a);
	stack_push_front_a(stack, val_b);
	ft_puts("sa");
}

void	swap_b(t_stack *stack)
{
	int	val_a;
	int	val_b;

	val_a = stack_pop_front_b(stack);
	val_b = stack_pop_front_b(stack);
	stack_push_front_b(stack, val_a);
	stack_push_front_b(stack, val_b);
	ft_puts("sb");
}
