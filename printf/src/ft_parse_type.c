/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:09 by yjung             #+#    #+#             */
/*   Updated: 2020/11/05 22:48:27 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_parse_lh(const char **format, t_set *set, va_list ap)
{
	while (**format == 'l' || **format == 'h')
	{
		if (**format == 'l')
		{
			if (*(*format + 1) == 'l' && *((*format)++))
				set->type = "ll";
			else if (*(*format + 1) != 'l' && *(*format - 1) != 'l' && \
			*((*format)++))
				set->type = "l";
		}
		else if (**format == 'h')
		{
			if (*(*format + 1) == 'h' && *((*format)++))
				set->type = "hh";
			else if (*(*format + 1) != 'h' && *(*format - 1) != 'h' && \
			*((*format)++))
				set->type = "h";
		}
	}
}

void		ft_parse_type(const char **format, t_set *set, va_list ap)
{
	if (**format == 'd' || **format == 'i' || **format == 'c' || \
	**format == 's' || **format == 'u' || **format == 'x' || **format == 'X' \
	|| **format == 'p' || **format == 'o')
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
		(*format)++;
	}
}
