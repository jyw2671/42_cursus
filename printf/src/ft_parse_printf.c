/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:11:56 by yjung             #+#    #+#             */
/*   Updated: 2020/11/04 21:43:49 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parse_flag(const char **format, t_set *set)
{
	while (**format == '0' || **format == '-' || \
	**format == '+' || **format == ' ' || **format == '#')
	{
		if (**format == ' ' && *((*format)++))
			set->s_flag = 1;
		else if (**format == '0' && *((*format)++))
			set->z_flag = 1;
		else if (**format == '-' && *((*format)++))
			set->lefted = 1;
		else if (**format == '+' && *((*format)++))
			set->sign = 1;
		else if (**format == '#' && *((*format)++))
			set->hash = 2;
	}
}

static void	ft_parse_width(const char **format, t_set *set, va_list ap)
{
	if (**format == '*' && **format && *((*format)++))
	{
		set->tmp_i = va_arg(ap, int);
		if (set->tmp_i < 0)
		{
			set->wid = -set->tmp_i;
			set->lefted = 1;
		}
		else if (set->tmp_i >= 0)
			set->wid = set->tmp_i;
	}
	else
	{
		set->wid = 0;
		while (**format >= '0' && **format <= '9')
			set->wid = set->wid * 10 + (*((*format)++) - '0');
	}
}

static void	ft_parse_precision(const char **format, t_set *set, va_list ap)
{
	if (**format == '*' && **format && *((*format)++))
	{
		set->ast_p_check = 0;
		set->tmp_i = va_arg(ap, int);
		if (set->tmp_i < 0 && (set->ast_p_check++) > -1)
			set->prec = -set->tmp_i;
		else if (set->tmp_i >= 0)
			set->prec = set->tmp_i;
	}
	else
	{
		set->prec_com = 1;
		while (**format == '0' && *(*format + 1) && *(++(*format)) == '0')
			(*format)++;
		if (**format >= '1' && **format <= '9')
		{
			set->prec = 0;
			while (**format >= '0' && **format <= '9')
				set->prec = set->prec * 10 + (*((*format)++) - '0');
			set->ast_p_check = 0;
		}
	}
}

int			ft_parse_printf(const char **format, t_set *set, va_list ap)
{
	while (**format == '-' || **format == '+' || **format == ' ' || \
	**format == '#' || (**format >= '0' && **format <= '9') || \
	**format == '*' || **format == '.' || **format == 'l' || **format == 'h')
	{
		if (**format == '0' || **format == '-' || \
		**format == '+' || **format == ' ' || **format == '#')
			ft_parse_flag(format, set);
		else if (**format == '*' || (**format >= '1' && **format <= '9'))
			ft_parse_width(format, set, ap);
		else if (**format == '.' && **format && *((*format)++))
			ft_parse_precision(format, set, ap);
		else if (**format == 'l' || **format == 'h')
			ft_parse_lh(format, set, ap);
	}
	if (**format == '%')
	{
		ft_check_parse(format, set, ap);
		return (0);
	}
	ft_parse_type(format, set, ap);
	return (0);
}
