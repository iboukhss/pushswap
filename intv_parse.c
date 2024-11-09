/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:16:01 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/09 16:16:52 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	intv_delete(t_intv *intv)
{
	free(intv->data);
	free(intv);
}

t_intv	*intv_parse(t_strv *strs)
{
	t_intv		*nums;

	nums = malloc(sizeof(*nums));
	if (nums == NULL)
	{
		return (NULL);
	}
	nums->len = 0;
	nums->cap = strs->len;
	nums->data = malloc(nums->cap * sizeof(*nums->data));
	if (nums->data == NULL)
	{
		free(nums);
		return (NULL);
	}
	while (nums->len < strs->len && nums->len < nums->cap)
	{
		if (ft_atoi(&nums->data[nums->len], strs->data[nums->len]) != 0)
		{
			intv_delete(nums);
			return (NULL);
		}
		nums->len++;
	}
	return (nums);
}
