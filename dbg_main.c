/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbg_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 23:06:03 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/02 16:43:06 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dbg_main.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void	sequence_init(int *array, ptrdiff_t array_size)
{
	ptrdiff_t	i;

	i = 0;
	while (i < array_size)
	{
		array[i] = i + 1;
		i++;
	}
}

void	shuffle(int *array, ptrdiff_t array_size)
{
	ptrdiff_t	i;
	ptrdiff_t	j;
	int			tmp;

	srand(42);
	i = array_size - 1;
	while (i > 0)
	{
		j = rand() % (i + 1);
		tmp = array[i];
		array[i] = array[j];
		array[j] = tmp;
		i--;
	}
}

void	stack_print(t_stack *stack)
{
	int	*ap;
	int	*bp;

	printf("A   |   B\n");
	printf("----+----\n");
	ap = stack->beg_a;
	bp = stack->beg_b;
	while (ap < stack->end_a || bp < stack->end_b)
	{
		if (ap < stack->end_a)
			printf("%-3d |", *ap++);
		else
			printf("  . |");
		if (bp < stack->end_b)
			printf(" %3d\n", *bp++);
		else
			printf("   .\n");
	}
}

void	chunk_print(t_chunk *chunk, const char *chunk_name)
{
	int	*cp;
	char loc[4][6] = {
		"TOP_A",
		"BOT_A",
		"TOP_B",
		"BOT_B",
	};

	printf("%4s: ", chunk_name);
	cp = chunk->beg;
	while (cp < chunk->end)
	{
		printf("%d, ", *cp);
		++cp;
	}
	printf("(len = %td), ", chunk->len);
	printf("(pos = %s)\n", loc[chunk->pos]);
}

void	sort_print(t_sort *sort)
{
	ptrdiff_t	i;

	i = 0;
	printf("***********************************************************\n");
	printf("arr : ");
	while (i < sort->size)
	{
		printf("%d, ", sort->arr[i]);
		++i;
	}
	printf("\n");
	printf("size: %td\n", sort->size);
	printf("pi  : %td\n", sort->pi);
	printf("qi  : %td\n", sort->qi);
	printf("p   : %d\n", sort->p);
	printf("q   : %d\n", sort->q);
	printf("***********************************************************\n");
}

void	state_print(t_state *state)
{
	printf("===========================================================\n");
	chunk_print(&state->curr, "curr");
	chunk_print(&state->min, "min");
	chunk_print(&state->mid, "mid");
	chunk_print(&state->max, "max");
	printf("===========================================================\n");
}
