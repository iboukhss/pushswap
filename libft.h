/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:45:41 by iboukhss          #+#    #+#             */
/*   Updated: 2024/11/10 22:23:12 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_strv
{
	char		**data;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_strv;

typedef struct s_intv
{
	int			*data;
	ptrdiff_t	len;
	ptrdiff_t	cap;
}	t_intv;

// Print
int		ft_printf(const char *format, ...);
int		ft_puts(const char *s);

// Memory
void	*ft_memcpy(void *dst, const void *src, ptrdiff_t n);
void	*ft_memmove(void *dst, const void *src, ptrdiff_t n);
void	*ft_realloc(void *ptr, ptrdiff_t old_size, ptrdiff_t new_size);

// Strings
char	*ft_strdup(const char *str);
char	*ft_strndup(const char *str, ptrdiff_t n);

// Other
int		ft_atoi(int *out_val, const char *str);
void	ft_quicksort(int *array, ptrdiff_t array_size);

// String arrays
t_strv	*strv_split(const char *str, int delim);
t_strv	*strv_dup(char **argv, ptrdiff_t argc);
void	strv_delete(t_strv *strv);

// Int arrays
t_intv	*intv_parse(t_strv *strs);
void	intv_delete(t_intv *intv);

#endif
