/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 22:11:56 by yjung             #+#    #+#             */
/*   Updated: 2020/10/28 06:23:26 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_parse_flag(const char **format, t_set *set)
{
	while (**format == '0' || **format == '-' || \
	**format == '+' || **format == ' ')
	{
		if (**format == ' ' && *((*format)++))
			set->s_flag = 1;
		else if (**format == '0' && *((*format)++))
			set->z_flag = 1;
		else if (**format == '-' && *((*format)++))
			set->lefted = 1;
		else if (**format == '+' && *((*format)++))
			set->sign = 1;
	}
}

static void	ft_parse_width(const char **format, t_set *set, va_list ap)
{
	if (**format == '*' && *((*format)++))
	{
		set->ast_w_val = va_arg(ap, int);
		set->ast_cnt++;
		if (set->ast_w_val < 0)
		{
			set->wid = -set->ast_w_val;
			set->lefted = 1;
		}
		else if (set->ast_w_val >= 0)
			set->wid = set->ast_w_val;
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
		set->ast_p_val = va_arg(ap, int);
		if (set->ast_p_val < 0)
		{
			set->prec = -set->ast_p_val;
			set->ast_p_check = 1;
		}
		else if (set->ast_p_val >= 0)
			set->prec = set->ast_p_val;
	}
	else
	{
		if (**format == '0')
			set->z_flag = 1;
		while ((**format == '0') && *((*format)++) == '0')
			set->z_flag = 1;
		set->prec_cnt = 0;
		if (**format >= '1' && **format <= '9')
			set->ast_p_check = 0;
		while (**format >= '0' && **format <= '9')
			set->prec_cnt = set->prec_cnt * 10 + (*((*format)++) - '0');
		set->prec = set->prec_cnt;
	}
}

static void	ft_parse_type(const char **format, t_set *set)
{
	if (**format == 'd' || **format == 'i')
		set->type = 'd';
	else if (**format == 'c')
		set->type = 'c';
	else if (**format == 's')
		set->type = 's';
}

int			ft_parse_printf(const char **format, t_set *set, va_list ap)
{
	while (**format == '-' || **format == '+' || **format == ' ' || \
	(**format >= '0' && **format <= '9') || **format == '*')
	{
		if (**format == '0' || **format == '-' || \
		**format == '+' || **format == ' ')
			ft_parse_flag(format, set);
		else if (**format == '*' || (**format >= '1' && **format <= '9'))
			ft_parse_width(format, set, ap);
		else if (**format == '.' && *((*format)++))
			ft_parse_precision(format, set, ap);
		else if (**format == '%')
		{
			ft_check_parse(format, set, ap);
			return (0);
		}
	}
	ft_parse_type(format, set);
	ft_type_printf(set, ap);
	return (0);
}
