/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/02 01:22:34 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"
#include "dbg_main.h"

#include <stdio.h>

int	main(void)
{
	int nums[20];
	sequence_init(nums, 20);
	shuffle(nums, 20);

	t_stack *stk = stack_new(nums, 20);

	stack_qsort(stk, nums, 20);

	stack_delete(stk);
}
