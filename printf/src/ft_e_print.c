/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:33:14 by yjung             #+#    #+#             */
/*   Updated: 2020/11/20 01:03:33 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	ft_dtoa_e(t_set *set, int cnt)
{
	int		len;

	if (set->tmp_1 != 0 && ft_int_cnt(set->val_ul) == ft_int_cnt(set->tmp_1))
	{
		set->val_ul /= 10;
		cnt++;
		if (set->val == 0 && set->val_sign == 1)
			cnt -= 2;
	}
	if (set->prec == 0 && set->prec_com != 0)
		len = ft_int_cnt(set->val_ul) + 4;
	else
		len = ft_int_cnt(set->val_ul) + 5;
	set->tmp_s = ((char *)malloc(sizeof(char) * (len + 1)));
	set->tmp_s[len--] = '\0';
	ft_dtoa_e_print(set, cnt, len);
	len -= 4;
	while (len > 1)
	{
		set->tmp_s[len--] = set->val_ul % 10 + '0';
		set->val_ul /= 10;
	}
	if (!(set->prec == 0 && set->prec_com != 0))
		set->tmp_s[len--] = '.';
	set->tmp_s[len] = set->val_ul + '0';
}

static void	ft_cnt_exp(t_double *num, t_set *set, int prec)
{
	unsigned long long	tmp;

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
		while (tmp > 0)
		{
			tmp /= 10;
			set->cnt++;
		}
		set->cnt = (set->cnt - set->cmp) - 1;
	}
}

static void	ft_value_set(t_double *num, t_set *set, int prec)
{
	if (set->cnt >= (prec + 1))
		while (set->cnt > (prec + 1))
			set->val_ul /= 10;
	else if (set->val > 0)
	{
		set->val_ul = (unsigned long long)((num->d - set->val) * \
		ft_pow((prec + 1) - set->cnt));
		set->val_ul += (set->val * ft_pow((prec + 1) - set->cnt));
	}
	else
	{
		set->cmp = prec;
		while ((15 - (prec - set->cnt)) > 1 && (prec++) > 0)
			set->val_ul /= 10;
		while (ft_int_cnt(set->val_ul) <= (set->cmp + 1))
			set->val_ul *= 10;
		while (ft_int_cnt(set->val_ul) > (set->cmp + 2))
			set->val_ul /= 10;
	}
	if (set->cnt < 0 && (set->cmp = 1))
		set->cnt = -set->cnt;
	else
		set->cmp = 0;
}

void		ft_dtoa_e_print(t_set *set, int cnt, int len)
{
	if (cnt == 0)
		set->cmp = 0;
	if (cnt >= 10)
	{
		while (cnt > 0)
		{
			set->tmp_s[len--] = (cnt % 10) + '0';
			cnt /= 10;
		}
	}
	else
	{
		if (cnt == 0)
			set->tmp_s[len--] = '0';
		else
			set->tmp_s[len--] = cnt + '0';
		set->tmp_s[len--] = '0';
	}
	if (set->cmp == 1)
		set->tmp_s[len--] = '-';
	else
		set->tmp_s[len--] = '+';
	set->tmp_s[len] = 'e';
}

void		ft_round_check_e(t_double *num, t_set *set, int prec)
{
	if (prec == 0 && set->prec_com == 0)
		prec = 6;
	set->cnt = 0;
	ft_cnt_exp(num, set, prec);
	if (((num->frac << (prec + 1 + (num->exp - 1023))) << 12) == 0)
	{
		ft_value_set(num, set, prec);
		ft_bankers_round(set);
		ft_dtoa_e(set, set->cnt);
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
		ft_dtoa_e(set, set->cnt);
	}
}
