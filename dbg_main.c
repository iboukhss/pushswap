/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:06:03 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/26 23:38:45 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_main.h"

#include <stdio.h>

void	stack_print(t_stack *stack)
{
	int	*ap;
	int	*bp;

	printf("A   : ");
	ap = stack->beg_a;
	while(ap < stack->end_a)
	{
		printf("%d, ", *ap);
		++ap;
	}
	printf("\nB   : ");
	bp = stack->beg_b;
	while (bp < stack->end_b)
	{
		printf("%d, ", *bp);
		++bp;
	}
	printf("\n");
}

void	chunk_print(t_chunk *chunk, const char *chunk_name)
{
	int	*cp;

	printf("%s: ", chunk_name);
	cp = chunk->beg;
	while (cp < chunk->end)
	{
		printf("%d, ", *cp);
		++cp;
	}
	printf("\n");
}

void	state_print(t_state *state)
{
	chunk_print(&state->curr, "curr");
	chunk_print(&state->min, "min ");
	chunk_print(&state->mid, "mid ");
	chunk_print(&state->max, "max ");
}
