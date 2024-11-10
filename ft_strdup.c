/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 22:23:29 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 22:27:20 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

static ptrdiff_t	ft_strlen(const char *s)
{
	const char	*end;

	end = s;
	while (*end)
	{
		++end;
	}
	return (end - s);
}

char	*ft_strdup(const char *str)
{
	ptrdiff_t	len;
	char		*dup;

	len = ft_strlen(str);
	dup = malloc((len + 1) * sizeof(*dup));
	if (dup == NULL)
	{
		return (NULL);
	}
	return (ft_memcpy(dup, str, len + 1));
}
