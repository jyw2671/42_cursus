/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:11:56 by yjung             #+#    #+#             */
/*   Updated: 2020/11/03 23:11:17 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

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
	if (**format == '*' && *((*format)++))
	{
		set->tmp_i = va_arg(ap, int);
		set->ast_cnt++;
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
		set->wid_cnt = 0;
		while (**format != '.' && (**format >= '0' && **format <= '9'))
			set->wid_cnt = set->wid_cnt * 10 + (*((*format)++) - '0');
		set->wid = set->wid_cnt;
	}
}

static void	ft_parse_precision(const char **format, t_set *set, va_list ap)
{
	if (**format == '*' && *((*format)++))
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
		while ((**format == '0') && **format == '0')
			(*format)++;
		if (**format >= '1' && **format <= '9')
		{
			set->prec_cnt = 0;
			while (**format >= '0' && **format <= '9')
				set->prec_cnt = set->prec_cnt * 10 + (*((*format)++) - '0');
			set->prec = set->prec_cnt;
			set->ast_p_check = 0;
		}
	}
}

static void	ft_parse_type(const char **format, t_set *set, va_list ap)
{
	if (**format == 'd' || **format == 'i' || **format == 'c' || \
	**format == 's' || **format == 'u' || **format == 'x' || **format == 'X' \
	|| **format == 'p')
	{
		if (**format == 'd' || **format == 'i' || **format == 'u')
			ft_int_check(format, set, ap);
		else if (**format == 'c')
			ft_char_set(set, ap);
		else if (**format == 's')
			ft_str_set(set, ap);
		else if (**format == 'x' || **format == 'X')
			ft_hex_set(format, set, ap);
		else if (**format == 'p')
			ft_ptr_set(set, ap);
		(*format)++;
	}
}

int			ft_parse_printf(const char **format, t_set *set, va_list ap)
{
	while (**format == '-' || **format == '+' || **format == ' ' || \
	**format == '#' || (**format >= '0' && **format <= '9') || \
	**format == '*' || **format == '.')
	{
		if (**format == '0' || **format == '-' || \
		**format == '+' || **format == ' ' || **format == '#')
			ft_parse_flag(format, set);
		else if (**format == '*' || (**format >= '1' && **format <= '9'))
			ft_parse_width(format, set, ap);
		else if (**format == '.' && *((*format)++))
			ft_parse_precision(format, set, ap);
	}
	if (**format == '%')
	{
		ft_check_parse(format, set, ap);
		return (0);
	}
	ft_parse_type(format, set, ap);
	return (0);
}
