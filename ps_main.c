/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/27 17:49:51 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"
#include "dbg_main.h"

int	main(void)
{
	int nums[9] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
	t_stack *stk = stack_new(nums, 9);
	t_state s;
	state_init(&s, stk, TOP_A, stk->end_a - stk->beg_a);
	state_print(&s);
	while (!chunk_is_empty(&s.curr))
	{
		if (chunk_peek(&s.curr) <= 3)
			state_push_min(&s);
		else if (chunk_peek(&s.curr) <= 6)
			state_push_mid(&s);
		else
			state_push_max(&s);
	}
	state_print(&s);

	state_init(&s, stk, s.max.pos, s.max.end - s.max.beg);
	state_print(&s);
	while (!chunk_is_empty(&s.curr))
	{
		if (chunk_peek(&s.curr) <= 7)
			state_push_min(&s);
		else if (chunk_peek(&s.curr) <= 8)
			state_push_mid(&s);
		else
			state_push_max(&s);
	}
	state_print(&s);
	stack_delete(stk);
}
