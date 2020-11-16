/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 16:25:48 by yjung             #+#    #+#             */
/*   Updated: 2020/11/16 23:02:08 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void		ft_big_int_set(t_set *set, va_list ap)
{
	t_double	num;
	t_bint		bint;

	num.d = (double)va_arg(ap, int);
	ft_big_int(set, &num, &bint);
}

void		ft_big_int(t_set *set, t_double *num, t_bint *bint)
{

	set->cnt = 0;
	ft_memset(bint->bianary, 0, sizeof(char) * 1074);
	// if ((num->exp - 1023) > 0)
	// {
		set->cmp = num->frac << (12 + set->prec);
		ft_memmove(bint->bianary, sizeof(char) * set->cmp, 51 - set->prec);
	// }
	// else
	// {
	// 	set->cmp = num->frac << (12 + set->prec);
	// 	ft_memmove(bint->bianary, sizeof(char) * set->cmp, 50);
	// 	set->tmp_s = ft_strjoin("1", sizeof(char) * set->cmp);
	// 	ft_memmove(bint->bianary, sizeof(char) * set->cmp, 51);
	// }
	printf("%s", bint->bianary);
}
