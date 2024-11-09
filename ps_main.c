/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/09 18:00:36 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"
#include "dbg_main.h"

#include "libft.h"

#include <unistd.h>

int	main(int argc, char **argv)
{
	t_stack	*stack;
	t_intv	*nums;

	if (argc < 2)
	{
		return (1);
	}
	if (stack_init_from_args(&stack, &nums, argv, argc) != 0)
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (1);
	}

	//stack_print(stack);

	stack_qsort(stack, nums->data, nums->len);

	//stack_print(stack);

	intv_delete(nums);
	stack_delete(stack);
	return (0);
}
