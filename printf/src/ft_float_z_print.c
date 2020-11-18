/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_z_print.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 21:56:06 by yjung             #+#    #+#             */
/*   Updated: 2020/11/19 00:11:41 by yjung            ###   ########.fr       */
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

static void	ft_nan_inf_set(t_set *set, t_double *num)
{
	set->tmp_s = ((char *)malloc(sizeof(char) * 4));
	set->tmp_s[3] = '\0';
	if (num->frac == 0)
	{
		set->tmp_s[0] = 'i';
		set->tmp_s[1] = 'n';
		set->tmp_s[2] = 'f';
	}
	else
	{
		set->tmp_s[0] = 'n';
		set->tmp_s[1] = 'a';
		set->tmp_s[2] = 'n';
		set->sign = 0;
		set->s_flag = 0;
	}
	set->z_flag = 0;
}

int			ft_nan_inf_print(t_set *set, t_double *num)
{
	if (num->sign == 0)
		set->val_sign = 0;
	else
	{
		set->val_sign = 1;
		num->d = -num->d;
	}
	if (num->exp == 2047)
	{
		ft_nan_inf_set(set, num);
		ft_float_lefted(set);
		return (-1);
	}
	return (0);
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
