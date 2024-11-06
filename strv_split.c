/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 18:36:01 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 19:04:51 by iboukhss         ###   ########.fr       */
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

// NOTE: Assume strndup never fails because I refuse to compromise on my style
// to fit less than 25 LOC.
static char	**parse_string(char **arr, ptrdiff_t arr_size, const char *str,
				int delim)
{
	const char	*beg;
	const char	*end;
	ptrdiff_t	i;

	i = 0;
	while (*str && i < arr_size)
	{
		while (*str && *str == delim)
		{
			++str;
		}
		if (*str != 0)
		{
			beg = str;
			while (*str && *str != delim)
			{
				++str;
			}
			end = str;
			arr[i++] = ft_strndup(beg, end - beg);
		}
	}
	arr[i] = NULL;
	return (arr);
}

char	**strv_split(const char *str, int delim)
{
	ptrdiff_t	count;
	char		**strs;

	count = count_tokens(str, delim);
	strs = malloc((count + 1) * sizeof(char *));
	if (strs == NULL)
	{
		return (NULL);
	}
	return (parse_string(strs, count, str, delim));
}

void	strv_free(char **strs)
{
	ptrdiff_t	i;

	i = 0;
	if (strs != NULL)
	{
		while (strs[i] != NULL)
		{
			free(strs[i++]);
		}
		free(strs);
	}
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

	char **args = strv_split(argv[1], ' ');
	for (ptrdiff_t i = 0; args[i] != NULL; i++)
	{
		printf("%td: %s\n", i, args[i]);
	}
	return (0);
}
*/
