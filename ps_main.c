/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 18:56:15 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps_main.h"
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
	stack_qsort(stack, nums->data, nums->len);
	intv_delete(nums);
	stack_delete(stack);
	return (0);
}
