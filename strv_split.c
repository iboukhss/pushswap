/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 06:02:49 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/07 07:40:20 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <string.h>

static char	*ft_strndup(const char *str, ptrdiff_t n)
{
	const char	*end;
	const char	*max;
	char		*dup;

	end = str;
	max = str + n;
	while (*end && end < max)
	{
		++end;
	}
	dup = malloc((end - str + 1) * sizeof(*dup));
	if (dup == NULL)
	{
		return (NULL);
	}
	memcpy(dup, str, end - str);
	dup[end - str] = '\0';
	return (dup);
}

static void	parse_string(t_strv *strs, const char *str, int delim)
{
	const char	*beg;
	const char	*end;
	ptrdiff_t	i;

	i = 0;
	while (*str && i < strs->cap)
	{
		while (*str && *str == delim)
		{
			++str;
		}
		if (*str != '\0')
		{
			beg = str;
			while (*str && *str != delim)
			{
				++str;
			}
			end = str;
			strs->data[i++] = ft_strndup(beg, end - beg);
		}
	}
}

static ptrdiff_t	count_tokens(const char *str, int delim)
{
	ptrdiff_t	count;

	count = 0;
	while (*str)
	{
		while (*str && *str == delim)
		{
			++str;
		}
		if (*str != '\0')
		{
			count += 1;
			while (*str && *str != delim)
			{
				++str;
			}
		}
	}
	return (count);
}

t_strv	*strv_split(const char *str, int delim)
{
	t_strv		*strs;
	ptrdiff_t	count;
	char		**tokens;

	strs = malloc(sizeof(*strs));
	if (strs == NULL)
	{
		return (NULL);
	}
	count = count_tokens(str, delim);
	tokens = malloc(count * sizeof(*tokens));
	if (tokens == NULL)
	{
		free(strs);
		return (NULL);
	}
	strs->data = tokens;
	strs->cap = count;
	parse_string(strs, str, delim);
	return (strs);
}

void	strv_delete(t_strv *strs)
{
	ptrdiff_t	i;

	i = 0;
	while (i < strs->cap)
	{
		free(strs->data[i++]);
	}
	free(strs);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (1);
	}
	printf("argv[1]: %s\n", argv[1]);

	t_strv *strs = strv_split(argv[1], ' ');
	for (ptrdiff_t i = 0; i < strs->cap; i++)
	{
		printf("%td: %s\n", i, strs->data[i]);
	}
	strv_delete(strs);
	return (0);
}
*/
