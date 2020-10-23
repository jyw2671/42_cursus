/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:11:56 by yjung             #+#    #+#             */
/*   Updated: 2020/10/23 22:33:51 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	ft_parse_num(const char *format, t_set *set)
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

static char	ft_parse_type(const char *format, t_set *set)
{
	if (*format == 'd' || *format == 'i' || *format == 'u')
		set->type = 'd';
	else if (*format == 's')
		set->type = 's';
	return (format);
}

char		ft_parse_printf(const char *format, t_set *set, va_list ap)
{
	format++;
	if (*format == '0')
		set->zero_flag = 1;
	else if (*format == '-')
		set->lefted = 1;
	else if (*format == '+')
		set->sign = 1;
	format++;
	if (*format == '.' || (*format <= '0' && *format >= '9'))
		ft_parse_num(format, &set);
	ft_parse_type(format, &set);
	ft_type_printf(&set, ap);
	return (format);
}
