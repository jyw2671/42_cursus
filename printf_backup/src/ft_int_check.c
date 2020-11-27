/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:40:18 by yjung             #+#    #+#             */
/*   Updated: 2020/11/18 23:21:49 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_int_check(const char **format, t_set *set, va_list ap)
{
	if (**format == 'd' || **format == 'i')
	{
		ft_print_l(set, ap);
		if (set->val < 0 && set->val_sign++ == 0)
			set->val_ul = -set->val;
		else
			set->val_ul = set->val;
	}
	else
		ft_print_ul(set, ap);
	ft_int_set(set);
}

void		ft_print_l(t_set *set, va_list ap)
{
	if (set->type_l == 2)
		set->val = va_arg(ap, long long);
	else if (set->type_l == 1)
		set->val = va_arg(ap, long);
	else if (set->type_h == 2)
		set->val = (char)va_arg(ap, int);
	else if (set->type_h == 1)
		set->val = (short)va_arg(ap, int);
	else
		set->val = va_arg(ap, int);
}

void		ft_print_ul(t_set *set, va_list ap)
{
	if (set->type_l == 2)
		set->val_ul = va_arg(ap, unsigned long long);
	else if (set->type_l == 1)
		set->val_ul = va_arg(ap, unsigned long);
	else if (set->type_h == 2)
		set->val_ul = (unsigned char)va_arg(ap, int);
	else if (set->type_h == 1)
		set->val_ul = (unsigned short)va_arg(ap, int);
	else
		set->val_ul = va_arg(ap, unsigned int);
}
