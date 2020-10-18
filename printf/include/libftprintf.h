/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 20:19:22 by yjung             #+#    #+#             */
/*   Updated: 2020/10/19 02:24:43 by yjung            ###   ########.fr       */
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
char	ft_parse_printf(const char *format, t_set *set);
size_t	ft_parse_num(const char *format);
int		ft_sprintf(char *out, const char *format, ...);

#endif
