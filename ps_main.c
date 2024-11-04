/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/04 02:03:13 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STACK_SIZE 50

#include "ps_main.h"
#include "dbg_main.h"

#include <stdio.h>

int	main(void)
{
	int nums[STACK_SIZE];
	sequence_init(nums, STACK_SIZE);
	shuffle(nums, STACK_SIZE);

	t_stack *stk = stack_new(nums, STACK_SIZE);

	stack_qsort(stk, nums, STACK_SIZE);

	stack_delete(stk);
}
