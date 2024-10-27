/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 20:02:51 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 11:55:27 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_MAIN_H
# define PS_MAIN_H

# include "s_stack.h"

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
	t_position	pos;
}	t_chunk;

// State handle for partitioning
typedef struct s_state
{
	t_stack	*stack;
	t_chunk curr;
	t_chunk	min;
	t_chunk	mid;
	t_chunk	max;
}	t_state;

// Push_swap operations
void	push_a(t_state *state);
void	push_b(t_state *state);
void	rotate_a(t_state *state);
void	rotate_b(t_state *state);
void	reverse_rotate_a(t_state *state);
void	reverse_rotate_b(t_state *state);

// Chunk functions
t_chunk	*chunk_at(t_state *state, t_position pos);
bool	chunk_is_empty(t_chunk *chunk);

// State operations
void	state_init(t_state *state, t_stack *stack, t_position pos, ptrdiff_t len);
void	state_push_min(t_state *state);
void	state_push_mid(t_state *state);
void	state_push_max(t_state *state);

#endif
