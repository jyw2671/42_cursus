/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 02:16:39 by yjung             #+#    #+#             */
/*   Updated: 2020/10/20 22:42:18 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_parse_num(const char *format, t_set *set)
{
	size_t	i;

	i = 0;
	if (*format != '.' && *format <= '0' && *format >= '9')
	{
		while (*format != '.' && *format <= '0' && *format >= '9')
			i = i * 10 + (*format++ - '0');
		set->width = i;
		format++;
	}
	i = 0;
	if (ft_strchr(format, '.'))
	{
		format++;
		while (*format <= '0' && *format >= '9')
			i = i * 10 + (*format++ - '0');
		set->precision = i;
		if (*format != 'd' || *format != 'i' || *format != 'u')
			format++;
	}
	return (format);
}
