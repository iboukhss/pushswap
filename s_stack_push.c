/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:12:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 22:20:21 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "libft.h"

void	stack_push_back_a(t_stack *stack, int value)
{
	ptrdiff_t	move_size;

	if (stack_is_full(stack))
	{
		return ;
	}
	move_size = stack->len_b * sizeof(int);
	ft_memmove(stack->beg_b + 1, stack->beg_b, move_size);
	*(stack->end_a) = value;
	stack->end_a += 1;
	stack->len_a += 1;
	stack->beg_b += 1;
	stack->end_b += 1;
}

void	stack_push_front_a(t_stack *stack, int value)
{
	ptrdiff_t	move_size;

	if (stack_is_full(stack))
	{
		return ;
	}
	move_size = (stack->len_a + stack->len_b) * sizeof(int);
	ft_memmove(stack->beg_a + 1, stack->beg_a, move_size);
	*(stack->beg_a) = value;
	stack->end_a += 1;
	stack->len_a += 1;
	stack->beg_b += 1;
	stack->end_b += 1;
}

void	stack_push_back_b(t_stack *stack, int value)
{
	if (stack_is_full(stack))
	{
		return ;
	}
	*(stack->end_b) = value;
	stack->end_b += 1;
	stack->len_b += 1;
}

void	stack_push_front_b(t_stack *stack, int value)
{
	ptrdiff_t	move_size;

	if (stack_is_full(stack))
	{
		return ;
	}
	move_size = stack->len_b * sizeof(int);
	ft_memmove(stack->beg_b + 1, stack->beg_b, move_size);
	*(stack->beg_b) = value;
	stack->end_b += 1;
	stack->len_b += 1;
}
