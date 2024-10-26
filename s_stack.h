/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:33 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 01:55:43 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_stack
{
	int			*data;
	int			*beg_a;
	int			*end_a;
	int			*beg_b;
	int			*end_b;
	ptrdiff_t	cap;
}	t_stack;

t_stack	*stack_new(ptrdiff_t stack_size);
void	stack_delete(t_stack *stack);
bool	stack_is_full(t_stack *stack);
bool	stack_a_is_empty(t_stack *stack);
bool	stack_b_is_empty(t_stack *stack);

void	stack_a_push_back(t_stack *stack, int value);
void	stack_a_push_front(t_stack *stack, int value);
void	stack_b_push_back(t_stack *stack, int value);
void	stack_b_push_front(t_stack *stack, int value);

int		stack_a_pop_back(int *out_val, t_stack *stack);
int		stack_a_pop_front(int *out_val, t_stack *stack);
int		stack_b_pop_back(int *out_val, t_stack *stack);
int		stack_b_pop_front(int *out_val, t_stack *stack);

#endif
