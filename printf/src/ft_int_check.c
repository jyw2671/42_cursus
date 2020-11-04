/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:40:18 by yjung             #+#    #+#             */
/*   Updated: 2020/11/04 21:37:49 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_int_check(const char **format, t_set *set, va_list ap)
{
	if (**format == 'd' || **format == 'i')
	{
		if ((set->val = va_arg(ap, int)) < 0 && set->val_sign++ == 0)
			set->val_ul = -set->val;
		else
			set->val_ul = set->val;
	}
	else
	{
		if ((set->val_ul = va_arg(ap, int)) >= 0)
			set->val_ul = set->val_ul;
		else
			return ;
	}
	ft_int_set(set);
}
