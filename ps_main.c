/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:25 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 19:54:34 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define STACK_SIZE 27

#include "ps_main.h"
#include "dbg_main.h"

#include "libft.h"
#include <stdlib.h>

int	main(int argc, char **argv)
{
	char	**args;
	int		*ints;

	if (argc < 2)
	{
		return (1);
	}
	else if (argc == 2)
	{
		return (1);
	}
	else
	{
		ints = malloc((argc - 1) * sizeof(*ints));
	}
	for (ptrdiff_t i = 0; i + 1 < argc; i++)
	{
		int err = ft_atoi(&ints[i], argv[i + 1]);
		if (err)
		{
			return (1);
		}
	}
	//int nums[STACK_SIZE];
	//sequence_init(nums, STACK_SIZE);
	//shuffle(nums, STACK_SIZE);

	t_stack *stk = stack_new(ints, argc - 1);

	//stack_print(stk);

	stack_qsort(stk, ints, argc - 1);

	//stack_print(stk);

	free(ints);
	stack_delete(stk);
}
