/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:40:18 by yjung             #+#    #+#             */
/*   Updated: 2020/11/02 20:55:56 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_int_check(const char **format, t_set *set, va_list ap)
{
	if (**format == 'd' || **format == 'i')
	{
		if ((set->tmp_i = va_arg(ap, int)) < 0 && set->val_sign++ == 0)
			set->val = -set->tmp_i;
		else
			set->val = set->tmp_i;
	}
	else
	{
		if ((set->tmp_u = va_arg(ap, int)) >= 0)
			set->val = set->tmp_u;
		else
			return ;
	}
	ft_int_set(set);
}
