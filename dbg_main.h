/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_main.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:06:17 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 23:37:15 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBG_MAIN_H
# define DBG_MAIN_H

#include "ps_main.h"

void	stack_print(t_stack *stack);
void	chunk_print(t_chunk *chunk, const char *chunk_name);
void	state_print(t_state *state);

#endif
