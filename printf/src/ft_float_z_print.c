/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_z_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:56:06 by yjung             #+#    #+#             */
/*   Updated: 2020/11/10 22:44:18 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_float_z_print(t_set *set)
{
	if (set->prec_com != 0 && set->prec == 0)
	{
		if (set->val_sign == 1)
			set->len += write(1, "-", 1);
		if (set->val == 0)
			set->len += write(1, "0", 1);
		while (set->val > 0)
		{
			set->tmp_c = set->val % 10 + '0';
			set->len += write(1, &set->tmp_c, 1);
			set->val /= 10;
		}
		return ;
	}
}
