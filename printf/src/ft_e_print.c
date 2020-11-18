/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:33:14 by yjung             #+#    #+#             */
/*   Updated: 2020/11/19 02:05:01 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_dtoa_e(t_set *set, int cnt, unsigned long long tmp)
{
	int		len;
	char	*c1;
	char	*c2;

	len = ft_int_cnt(set->val_ul);
	set->tmp_s[len--] = '.';
	while ((len + 1) > 0)
	{
		set->tmp_s[len--] = tmp % 10 + '0';
		tmp /= 10;
	}
}

static void	ft_bankers_round(t_set *set)
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
	ft_dtoa_e(set, set->cnt, set->val_ul);
}

static void	ft_cnt_exp(t_double *num, t_set *set, int prec)
{
	unsigned long long	tmp;

	set->cnt = 0;
	tmp = set->val;
	if (tmp > 0)
	{
		while (tmp >= 10)
		{
			tmp /= 10;
			set->cnt++;
		}
		set->val_ul = set->val;
	}
	else if (tmp == 0)
	{
		set->cmp = 15;
		set->val_ul = (unsigned long long)(num->d * ft_pow(set->cmp));
		tmp = set->val_ul;
		while (tmp >= 0)
		{
			tmp /= 10;
			set->cnt++;
		}
		set->cnt = set->cnt - set->cmp;
	}
}

static void	ft_value_set(t_double *num, t_set *set, int prec)
{
	int		i;

	i = (prec + 1) - set->cnt;
	if (set->cnt >= (prec + 1))
	{
		while (set->cnt > (prec + 1) && (set->cnt++) >= 0)
			set->val_ul /= 10;
	}
	else if (set->val > 0)
	{
		set->val_ul = (unsigned long long)((num->d - set->val) * ft_pow(i));
		set->val_ul += (set->val * ft_pow(i));
	}
	else
	{
		while ((prec + 1) > 0 && (prec--) > 0)
			set->val_ul /= 10;
	}
	if (set->cnt < 0)
	{
		set->cnt = -set->cnt;
		set->cmp = 1;
	}
	else
		set->cmp = 0;
}

void		ft_round_check_e(t_double *num, t_set *set, int prec)
{
	if (prec == 0 && set->prec_com == 0)
		prec = 6;
	ft_cnt_exp(num, set, prec);
	if (((num->frac << (prec + 1 + (num->exp - 1023))) << 12) == 0)
	{
		ft_value_set(num, set, prec);
		ft_bankers_round(set);
	}
	else
	{
		ft_value_set(num, set, prec);
		if ((set->val_ul % 10) >= 5)
		{
			set->tmp_1 = set->val_ul;
			set->val_ul /= 10;
			set->val_ul += 1;
		}
		else
			set->val_ul /= 10;
		ft_dtoa_e(set, set->cnt, set->val_ul);
	}
}
