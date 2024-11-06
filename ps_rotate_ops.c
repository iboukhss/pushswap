/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 02:56:31 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 14:52:21 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"

#include "libft.h"

void	rotate_a(t_stack *stack)
{
	int	val;

	val = stack_pop_front_a(stack);
	stack_push_back_a(stack, val);
	ft_puts("ra");
}

void	rotate_b(t_stack *stack)
{
	int	val;

	val = stack_pop_front_b(stack);
	stack_push_back_b(stack, val);
	ft_puts("rb");
}

void	reverse_rotate_a(t_stack *stack)
{
	int	val;

	val = stack_pop_back_a(stack);
	stack_push_front_a(stack, val);
	ft_puts("rra");
}

void	reverse_rotate_b(t_stack *stack)
{
	int	val;

	val = stack_pop_back_b(stack);
	stack_push_front_b(stack, val);
	ft_puts("rrb");
}
