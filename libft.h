/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/06 18:46:31 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>

void	ft_quicksort(int *array, ptrdiff_t array_size);
int		ft_atoi(int *out_val, const char *str);
int		ft_printf(const char *format, ...);
int		ft_puts(const char *s);

char	**strv_split(const char *str, int delim);
void	strv_free(char **strs);

#endif
