/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_stack.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iboukhss <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 19:45:33 by iboukhss          #+#    #+#             */
/*   Updated: 2024/10/25 19:47:08 by iboukhss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_STACK_H
# define S_STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int			*data;
	ptrdiff_t	*cap;
	ptrdiff_t	top_a;
	ptrdiff_t	bot_a;
	ptrdiff_t	top_b;
	ptrdiff_t	bot_b;
}	t_stack;

#endif
