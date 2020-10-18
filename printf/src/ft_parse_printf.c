/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:11:56 by yjung             #+#    #+#             */
/*   Updated: 2020/10/18 22:11:43 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		ft_parse_printf(const char *format, t_set *set)
{
	size_t	i;

	i = 0;
	format++;
	if (format == '0')
		set->zero_flag = 1;
	else if (format == '-')
		set->lefted = 1;
	else if (format == '+')
		set->sign = 1;
	format++;
	while (*format != '.' && *format <= '0' && *format >= '9')
		i = i * 10 + (*format++ - '0');
	set->width = i;
	i = 0;
	if (ft_strchr(format, '.'))
	{
		format++;
		while (*format <= '0' && *format >= '9')
			i = i * 10 + (*format++ - '0');
		set->precision = i;
	}
	return (format);
}
