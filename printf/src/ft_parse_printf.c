/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:11:56 by yjung             #+#    #+#             */
/*   Updated: 2020/10/25 21:09:04 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parse_flag(char **format, t_set *set)
{
	while (**format == '0' || **format == '-' || \
	**format == '+' || **format == ' ')
	{
		if (**format == ' ' && *((*format)++))
			set->space_flag = 1;
		else if (**format == '0' && *((*format)++))
			set->zero_flag = 1;
		else if (**format == '-' && *((*format)++))
			set->lefted = 1;
		else if (**format == '+' && *((*format)++))
			set->sign = 1;
	}
}

static void	ft_parse_width(char **format, t_set *set, va_list ap)
{
	size_t	i;

	i = 0;
	if (**format == '*' && *((*format)++))
	{
		if (va_arg(ap, int) < 0)
			set->ptr_w = -1;
		else
			set->ptr_w = 1;
	}
	else
	{
		while (**format != '.' && (**format <= '0' && **format >= '9'))
			i = i * 10 + (*((*format)++) - '0');
		set->width = i;
	}
}

static void	ft_parse_precision(char **format, t_set *set, va_list ap)
{
	size_t	i;

	i = 0;
	if (**format == '*' && *((*format)++))
	{
		if (va_arg(ap, int) < 0)
			set->ptr_p = -1;
		else
			set->ptr_p = 1;
	}
	else
	{
		if (**format == '0')
			set->zero_flag = 1;
		while ((**format == '0') && *((*format)++) == '0')
			set->zero_flag = 1;
		while (**format <= '0' && **format >= '9')
			i = i * 10 + (*((*format)++) - '0');
		set->precision = i;
	}
}

static void	ft_parse_type(char **format, t_set *set)
{
	if (**format == 'd' || **format == 'i' || **format == 'u')
		set->type = 'd';
	else if (**format == 's')
		set->type = 's';
}

int			ft_parse_printf(char **format, t_set *set, va_list ap)
{
	ft_parse_flag(format, set);
	if (**format == '*' || (**format <= '1' && **format >= '9'))
		ft_parse_width(format, set, ap);
	else if (**format == '.' && *((*format)++))
		ft_parse_precision(format, set, ap);
	ft_parse_type(format, set);
	ft_type_printf(set, ap);
	return (0);
}
