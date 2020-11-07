/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:10:25 by yjung             #+#    #+#             */
/*   Updated: 2020/11/07 21:35:38 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_sign_bit(t_set *set, va_list ap, t_num *num)
{
	num->d_val = va_arg(ap, double);
	if (num->sign == 0)
		set->val_sign = 0;
	else
		set->val_sign = 1;
	set->tmp_1 = ft_pow(set->prec);
}

void		ft_float_set(t_set *set, va_list ap)
{
	t_num	num;

	ft_sign_bit(set, ap, &num);
}
