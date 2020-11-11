/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:39:28 by yjung             #+#    #+#             */
/*   Updated: 2020/11/11 20:48:35 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_cmp_len(t_set *set)
{
	if (set->tmp_1 != 0)
	{
		if (ft_int_cnt(set->val_ul) == ft_int_cnt(set->tmp_1))
			set->val += 1;
	}
}

static void	ft_dtoa_f(t_set *set, int prec, unsigned long long tmp)
{
	int		len;

	tmp += (set->val * ft_pow(prec));
	ft_cmp_len(set);
	len = (ft_int_cnt(set->val) + prec) + 1;
	set->tmp_s = ((char *)malloc(sizeof(char) * (len + 1)));
	set->tmp_s[len--] = '\0';
	while (prec-- > 0)
	{
		set->tmp_s[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
	set->tmp_s[len--] = '.';
	while ((len + 1) > 0)
	{
		set->tmp_s[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
}

static void	ft_bankers_round(t_set *set, int prec)
{
	if ((set->val_ul % 10) == 0)
		set->val_ul /= 10;
	else if ((((set->val_ul / 10) % 10) % 2) == 0)
	{
		if ((set->val_ul % 10) > 5)
		{
			set->tmp_1 = set->val_ul;
			set->val_ul /= 10;
			set->val_ul += 1;
		}
		else
			set->val_ul /= 10;
	}
	else
	{
		if ((set->val_ul % 10) >= 5)
		{
			set->tmp_1 = set->val_ul;
			set->val_ul /= 10;
			set->val_ul += 1;
		}
		else
			set->val_ul /= 10;
	}
	ft_dtoa_f(set, prec, set->val_ul);
}

void		ft_round_check(t_double *num, t_set *set, int prec)
{
	if (prec == 0 && set->prec_com == 0)
		prec = 6;
	if (((num->frac << (prec + 1 + (num->exp - 1023))) \
	<< 12) == 0)
	{
		set->val_ul = (unsigned long long)((num->d - set->val) * \
			ft_pow(prec + 1));
		ft_bankers_round(set, prec);
	}
	else
	{
		set->val_ul = (unsigned long long)((num->d - set->val) * \
			ft_pow(prec + 1));
		if (set->val_ul % 10 >= 5)
		{
			set->tmp_1 = set->val_ul;
			set->val_ul /= 10;
			set->val_ul += 1;
		}
		else
			set->val_ul /= 10;
		ft_dtoa_f(set, prec, set->val_ul);
	}
}
