/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:02:51 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/09 18:02:36 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MAIN_H
# define PS_MAIN_H

# include "s_stack.h"

// Push_swap operations
typedef enum e_operation
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
}	t_operation;

// Relative position in the stack
typedef enum e_position
{
	TOP_A,
	BOT_A,
	TOP_B,
	BOT_B,
}	t_position;

// Stack chunk
typedef struct s_chunk
{
	int			*beg;
	int			*end;
	ptrdiff_t	len;
	t_position	pos;
}	t_chunk;

// State handle for partitioning
typedef struct s_state
{
	t_chunk		curr;
	t_chunk		min;
	t_chunk		mid;
	t_chunk		max;
	ptrdiff_t	cap;
}	t_state;

typedef struct s_sort
{
	int			*arr;
	ptrdiff_t	size;
	ptrdiff_t	pi;
	ptrdiff_t	qi;
	int			p;
	int			q;
}	t_sort;

// Push_swap operations
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	reverse_rotate_a(t_stack *stack);
void	reverse_rotate_b(t_stack *stack);

// State operations
void	state_init(t_state *state, t_stack *stack, ptrdiff_t len, t_position pos);

void	state_push_min(t_state *state, t_stack *stack);
void	state_push_mid(t_state *state, t_stack *stack);
void	state_push_max(t_state *state, t_stack *stack);

void	state_pop_min(t_state *state, t_stack *stack);
void	state_pop_mid(t_state *state, t_stack *stack);
void	state_pop_max(t_state *state, t_stack *stack);

// Chunk functions
t_chunk	*chunk_at(t_state *state, t_position pos);

bool	chunk_is_empty(t_state *state, t_position pos);
bool	chunk_is_full(t_state *state);

void	chunk_push(t_state *state, t_position pos);
void	chunk_pop(t_state *state, t_position pos);

int		chunk_data(t_chunk chunk);

// Sorting
void	stack_qsort(t_stack *stack, int *array, ptrdiff_t array_size);

#endif
