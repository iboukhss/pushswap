/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:57:54 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/08 22:58:03 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, ptrdiff_t n)
{
	char		*dp;
	const char	*sp;

	dp = dst;
	sp = src;
	while (n > 0)
	{
		*dp++ = *sp++;
		n--;
	}
	return (dst);
}
