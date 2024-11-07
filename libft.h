/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/07 07:40:29 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_strv
{
	char		**data;
	ptrdiff_t	cap;
}	t_strv;

void	ft_quicksort(int *array, ptrdiff_t array_size);
int		ft_atoi(int *out_val, const char *str);
int		ft_printf(const char *format, ...);
int		ft_puts(const char *s);

t_strv	*strv_split(const char *str, int delim);
void	strv_delete(t_strv *strs);

#endif
