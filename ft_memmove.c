/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 20:52:55 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 21:05:31 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// NOTE: First case is essentially memcpy.
void	*ft_memmove(void *dst, const void *src, ptrdiff_t n)
{
	char		*dp;
	const char	*sp;

	dp = dst;
	sp = src;
	if (dp < sp)
	{
		while (n > 0)
		{
			*dp++ = *sp++;
			n--;
		}
	}
	else
	{
		dp += n;
		sp += n;
		while (n > 0)
		{
			*--dp = *--sp;
			n--;
		}
	}
	return (dst);
}
