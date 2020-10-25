/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/10/25 21:09:07 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include "libft.h"

typedef struct	s_set
{
	int			zero_flag;
	int			space_flag;
	int			lefted;
	int			sign;
	int			ptr_w;
	int			ptr_p;
	int			width;
	int			precision;
	char		type;

}				t_set;

int		ft_printf(const char *format, ...);
int		ft_parse_printf(char **format, t_set *set, va_list ap);
void	ft_type_printf(t_set *set, va_list ap);
void	ft_int_set(t_set *set, va_list ap);
int		ft_sprintf(char *out, const char *format, ...);

#endif
