/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:09 by yjung             #+#    #+#             */
/*   Updated: 2020/11/10 19:47:47 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_n_type(t_set *set, va_list ap)
{
	int *n_ret;

	n_ret = va_arg(ap, int*);
	n_ret = &set->len;
	set->len_ret += set->len;
	set->len = 0;
}

void		ft_parse_ex_type(const char **format, t_set *set, va_list ap)
{
	while (**format == 'l' || **format == 'h')
	{
		if (**format == 'l')
		{
			set->type_l = 1;
			if (*(++(*format)) == 'l')
				set->type_l = 2;
			while (**format == 'l')
				(*format)++;
		}
		else if (**format == 'h')
		{
			set->type_h = 1;
			if (*(++(*format)) == 'h')
				set->type_h = 2;
			while (**format == 'h')
				(*format)++;
		}
	}
}

void		ft_parse_type(const char **format, t_set *set, va_list ap)
{
	if (**format == 'd' || **format == 'i' || **format == 'c' || \
	**format == 's' || **format == 'u' || **format == 'x' || **format == 'X' \
	|| **format == 'p' || **format == 'o' || **format == 'n' || **format == 'f')
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
		else if (**format == 'o')
			ft_oct_set(set, ap);
		else if (**format == 'n')
			ft_print_n_type(set, ap);
		else if (**format == 'f')
			ft_float_set(set, ap);
		(*format)++;
	}
}
