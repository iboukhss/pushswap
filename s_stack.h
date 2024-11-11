/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:33 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/11 14:47:00 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stdbool.h>
# include <stddef.h>

// Forward declaration to avoid unnecessary includes
typedef struct s_intv	t_intv;

typedef struct s_stack
{
	int			*data;
	int			*beg_a;
	int			*end_a;
	int			*beg_b;
	int			*end_b;
	ptrdiff_t	len_a;
	ptrdiff_t	len_b;
	ptrdiff_t	cap;
}	t_stack;

// Init functions
t_stack	*stack_new(int *array, ptrdiff_t array_size);
void	stack_delete(t_stack *stack);

int		stack_init_from_args(t_stack **stack, t_intv **nums, char **argv,
			int argc);

// Peek functions
bool	stack_is_full(t_stack *stack);
bool	stack_is_empty_a(t_stack *stack);
bool	stack_is_empty_b(t_stack *stack);
bool	stack_is_sorted_a(t_stack *stack);

// Not used
int		stack_front_a(t_stack *stack);
int		stack_front_b(t_stack *stack);
int		stack_back_a(t_stack *stack);
int		stack_back_b(t_stack *stack);

// Push operations
void	stack_push_back_a(t_stack *stack, int value);
void	stack_push_front_a(t_stack *stack, int value);
void	stack_push_back_b(t_stack *stack, int value);
void	stack_push_front_b(t_stack *stack, int value);

// Pop operations
int		stack_pop_back_a(t_stack *stack);
int		stack_pop_front_a(t_stack *stack);
int		stack_pop_back_b(t_stack *stack);
int		stack_pop_front_b(t_stack *stack);

#endif
