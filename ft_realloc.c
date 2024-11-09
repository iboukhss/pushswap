/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:25:20 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/08 22:57:26 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>

// NOTE: This is some serious work.
void	*ft_realloc(void *ptr, ptrdiff_t old_size, ptrdiff_t new_size)
{
	void	*new;

	if (ptr == NULL)
	{
		return (malloc(new_size));
	}
	else if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	else if (new_size <= old_size)
	{
		return (ptr);
	}
	new = malloc(new_size);
	if (new == NULL)
	{
		return (NULL);
	}
	ft_memcpy(new, ptr, old_size);
	free(ptr);
	return (new);
}
