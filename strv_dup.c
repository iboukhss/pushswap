/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_dup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:50:13 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/08 23:48:56 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <string.h>

static t_strv	*fill_data(t_strv *sv, char **av, ptrdiff_t ac)
{
	ptrdiff_t	i;

	i = 0;
	while (i < ac && i < sv->cap - 1)
	{
		sv->data[i] = strdup(av[i]);
		if (sv->data[i] == NULL)
		{
			strv_delete(sv);
			return (NULL);
		}
		sv->len++;
		i++;
	}
	sv->data[sv->len] = NULL;
	return (sv);
}

t_strv	*strv_dup(char **argv, ptrdiff_t argc)
{
	t_strv	*dup;

	dup = malloc(sizeof(*dup));
	if (dup == NULL)
	{
		return (NULL);
	}
	dup->len = 0;
	dup->cap = argc + 1;
	dup->data = malloc(dup->cap * sizeof(*dup->data));
	if (dup->data == NULL)
	{
		free(dup);
		return (NULL);
	}
	return (fill_data(dup, argv, argc));
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_strv *args = strv_dup(argv, argc);
	for (ptrdiff_t i = 0; i < args->len; i++)
	{
		printf("%td: %s\n", i, args->data[i]);
	}
	strv_delete(args);
	return (0);
}
*/
