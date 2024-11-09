/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:45:06 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/09 18:01:21 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "s_stack.h"

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

static int	init_stack(t_stack **stack, t_intv *nums)
{
	*stack = stack_new(nums->data, nums->len);
	return (*stack == NULL);
}

static bool	has_duplicates(t_intv *nums)
{
	ptrdiff_t	i;
	ptrdiff_t	j;

	i = 0;
	while (i < nums->len - 1)
	{
		j = i + 1;
		while (j < nums->len)
		{
			if (nums->data[i] == nums->data[j])
			{
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

static int	init_nums(t_intv **nums, t_strv *args)
{
	*nums = intv_parse(args);
	if (*nums == NULL)
	{
		return (1);
	}
	if (has_duplicates(*nums))
	{
		intv_delete(*nums);
		return (1);
	}
	return (0);
}

static int	init_args(t_strv **args, char **argv, int argc)
{
	if (argc == 2)
	{
		*args = strv_split(argv[1], ' ');
	}
	else
	{
		*args = strv_dup(argv + 1, argc - 1);
	}
	return (*args == NULL);
}

int	stack_init_from_args(t_stack **stack, t_intv **nums, char **argv, int argc)
{
	t_strv	*args;

	if (init_args(&args, argv, argc) != 0)
	{
		return (1);
	}
	if (init_nums(nums, args) != 0)
	{
		strv_delete(args);
		return (1);
	}
	if (init_stack(stack, *nums) != 0)
	{
		strv_delete(args);
		intv_delete(*nums);
		return (1);
	}
	strv_delete(args);
	return (0);
}
