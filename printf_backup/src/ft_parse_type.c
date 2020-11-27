/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 17:16:09 by yjung             #+#    #+#             */
/*   Updated: 2020/11/20 16:11:45 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_set_n_type(t_set *set, va_list ap)
{
	long long	*num_ll;
	long		*num_l;
	char		*num_c;
	short int	*num_s;

	if (set->type_l == 2)
	{
		num_ll = va_arg(ap, long long int *);
		*num_ll = set->len;
	}
	else if (set->type_l == 1)
	{
		num_l = va_arg(ap, long int *);
		*num_l = set->len;
	}
	else if (set->type_h == 2)
	{
		num_c = va_arg(ap, char *);
		*num_c = set->len;
	}
	else if (set->type_h == 1)
	{
		num_s = va_arg(ap, short int *);
		*num_s = set->len;
	}
}

static void	ft_print_n_type(t_set *set, va_list ap)
{
	int *num;

	if (set->type_l != 0 || set->type_h != 0)
		ft_set_n_type(set, ap);
	else
	{
		num = va_arg(ap, int *);
		*num = set->len;
	}
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
	|| **format == 'p' || **format == 'o' || **format == 'n' || **format == \
	'f' || **format == 'e')
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
		else if (**format == 'e')
			ft_e_set(set, ap);
		(*format)++;
	}
}
