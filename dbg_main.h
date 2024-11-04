/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_main.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:06:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/02 16:04:20 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_MAIN_H
# define DBG_MAIN_H

#include "ps_main.h"

void	stack_print(t_stack *stack);
void	chunk_print(t_chunk *chunk, const char *chunk_name);
void	state_print(t_state *state);
void	sort_print(t_sort *sort);

void	sequence_init(int *array, ptrdiff_t array_size);
void	shuffle(int *array, ptrdiff_t array_size);

#endif
