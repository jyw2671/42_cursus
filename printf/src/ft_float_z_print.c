/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_z_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:56:06 by yjung             #+#    #+#             */
/*   Updated: 2020/11/11 19:08:37 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_float_z_prec(t_set *set)
{
	set->cnt = ft_int_cnt(set->val);
	set->tmp_s = ((char *)malloc(sizeof(char) * (set->cnt + 1)));
	set->tmp_s[set->cnt--] = '\0';
	if (set->val == 0)
		set->tmp_s[set->cnt] = '0';
	while (set->val > 0)
	{
		if (set->cnt > 0)
			set->tmp_s[set->cnt--] = (set->val % 10) + '0';
		else
			set->tmp_s[set->cnt] = (set->val % 10) + '0';
		set->val /= 10;
	}
}

void		ft_float_z_print(t_set *set, t_double *num)
{
	set->val = (long)(num->d * 10);
	if ((((set->val / 10) % 10) % 2) == 0)
	{
		if (set->val % 10 > 5)
		{
			set->val /= 10;
			set->val += 1;
		}
		else
			set->val /= 10;
	}
	else
	{
		if (set->val % 10 >= 5)
		{
			set->val /= 10;
			set->val += 1;
		}
		else
			set->val /= 10;
	}
	ft_float_z_prec(set);
}
