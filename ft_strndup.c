/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:23:53 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/08 22:57:16 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

char	*ft_strndup(const char *str, ptrdiff_t n)
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
	ft_memcpy(dup, str, end - str);
	dup[end - str] = '\0';
	return (dup);
}
