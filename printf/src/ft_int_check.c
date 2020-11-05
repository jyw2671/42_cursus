/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:40:18 by yjung             #+#    #+#             */
/*   Updated: 2020/11/05 22:48:30 by yjung            ###   ########.fr       */
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
	if (ft_strncmp(set->type, "ll", 2) == 0)
		set->val = va_arg(ap, long long);
	else if (ft_strncmp(set->type, "l", 1) == 0)
		set->val = va_arg(ap, long);
	else
		set->val = va_arg(ap, int);
}

void		ft_print_ul(t_set *set, va_list ap)
{
	if (ft_strncmp(set->type, "ll", 2) == 0)
		set->val_ul = va_arg(ap, unsigned long long);
	else if (ft_strncmp(set->type, "l", 1) == 0)
		set->val_ul = va_arg(ap, unsigned long);
	else
		set->val_ul = va_arg(ap, unsigned int);
}
