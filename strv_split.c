/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strv_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 06:02:49 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/09 16:17:15 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

void	strv_delete(t_strv *strv)
{
	ptrdiff_t	i;

	i = 0;
	while (i < strv->len)
	{
		free(strv->data[i++]);
	}
	free(strv->data);
	free(strv);
}

static ptrdiff_t	get_next_token(char **tok, char **pos, int delim)
{
	const char	*beg;
	const char	*end;

	beg = *pos;
	while (*beg && *beg == delim)
	{
		beg++;
	}
	if (*beg == '\0')
	{
		*pos = (char *)beg;
		return (-1);
	}
	end = beg;
	while (*end && *end != delim)
	{
		end++;
	}
	*tok = ft_strndup(beg, end - beg);
	*pos = (char *)end;
	return (end - beg);
}

static t_strv	*tokenize_string(t_strv *strv, const char *str, int delim)
{
	char		*token;
	char		*pos;
	ptrdiff_t	old_size;
	void		*new_data;

	pos = (char *)str;
	while (get_next_token(&token, &pos, delim) > 0)
	{
		if (token == NULL)
		{
			strv_delete(strv);
			return (NULL);
		}
		if (strv->len + 1 >= strv->cap)
		{
			old_size = strv->cap * sizeof(*strv->data);
			new_data = ft_realloc(strv->data, old_size, old_size * 2);
			if (new_data == NULL)
			{
				strv_delete(strv);
				return (NULL);
			}
			strv->data = new_data;
			strv->cap *= 2;
		}
		strv->data[strv->len++] = token;
	}
	strv->data[strv->len] = NULL;
	return (strv);
}

t_strv	*strv_split(const char *str, int delim)
{
	t_strv	*strv;

	strv = malloc(sizeof(*strv));
	if (strv == NULL)
	{
		return (NULL);
	}
	strv->len = 0;
	strv->cap = 4;
	strv->data = malloc(strv->cap * sizeof(*strv->data));
	if (strv->data == NULL)
	{
		free(strv);
		return (NULL);
	}
	return (tokenize_string(strv, str, delim));
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		return (1);
	}
	t_strv *toks = strv_split(argv[1], ' ');
	if (toks == NULL)
	{
		return (1);
	}
	for (ptrdiff_t i = 0; i <= toks->len; i++)
	{
		printf("%td: %s\n", i, toks->data[i]);
	}
	printf("Capacity (%td / %td)\n", toks->len, toks->cap);
	strv_delete(toks);
	return (0);
}
*/
