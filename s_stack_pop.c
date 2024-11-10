/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack_pop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 01:12:53 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 22:21:11 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"
#include "libft.h"

int	stack_pop_back_a(t_stack *stack)
{
	ptrdiff_t	move_size;
	int			val;

	if (stack_is_empty_a(stack))
	{
		return (-42);
	}
	val = stack_back_a(stack);
	move_size = stack->len_b * sizeof(int);
	ft_memmove(stack->beg_b - 1, stack->beg_b, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_a -= 1;
	stack->len_a -= 1;
	stack->beg_b -= 1;
	stack->end_b -= 1;
	return (val);
}

int	stack_pop_front_a(t_stack *stack)
{
	ptrdiff_t	move_size;
	int			val;

	if (stack_is_empty_a(stack))
	{
		return (-42);
	}
	val = stack_front_a(stack);
	move_size = (stack->len_a + stack->len_b - 1) * sizeof(int);
	ft_memmove(stack->beg_a, stack->beg_a + 1, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_a -= 1;
	stack->len_a -= 1;
	stack->beg_b -= 1;
	stack->end_b -= 1;
	return (val);
}

int	stack_pop_back_b(t_stack *stack)
{
	int	val;

	if (stack_is_empty_b(stack))
	{
		return (-42);
	}
	val = stack_back_b(stack);
	*(stack->end_b - 1) = 0;
	stack->end_b -= 1;
	stack->len_b -= 1;
	return (val);
}

int	stack_pop_front_b(t_stack *stack)
{
	ptrdiff_t	move_size;
	int			val;

	if (stack_is_empty_b(stack))
	{
		return (-42);
	}
	val = stack_front_b(stack);
	move_size = (stack->len_b - 1) * sizeof(*stack->data);
	ft_memmove(stack->beg_b, stack->beg_b + 1, move_size);
	*(stack->end_b - 1) = 0;
	stack->end_b -= 1;
	stack->len_b -= 1;
	return (val);
}
