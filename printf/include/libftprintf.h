/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/10/23 22:33:54 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
#define LIBFTPRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include "libft.h"

typedef struct	s_set
{
	void		*val;
	char		type;
	int			zero_flag;
	int			space_flag;
	int			lefted;
	int			width;
	int			precision;
	int			sign;
}				t_set;

int		ft_printf(const char *format, ...);
char	ft_parse_printf(const char *format, t_set *set, va_list ap);
// char	ft_parse_num(const char *format, t_set *set);
// char	ft_parse_type(const char *format, t_set *set);
void	ft_type_printf(t_set *set, va_list ap);
void	*ft_int_set(t_set *set, va_list ap);
int		ft_sprintf(char *out, const char *format, ...);

#endif
