/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:33:14 by yjung             #+#    #+#             */
/*   Updated: 2020/11/19 00:11:40 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_dtoa_e(t_set *set, int prec, unsigned long long tmp)
{
	int		len;

	tmp += (set->val * ft_pow(prec));
	if (set->tmp_1 != 0)
	{
		if (ft_int_cnt(set->val_ul) == ft_int_cnt(set->tmp_1))
			set->val += 1;
	}
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
	ft_dtoa_e(set, prec, set->val_ul);
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
			set->cnt--;
		}
		set->val_ul = set->val;
	}
	else if (tmp == 0)
	{
		set->cmp = 15;
		set->val_ul = (long long)(num->d * ft_pow(set->cmp));
		tmp = set->val_ul;
		while (tmp >= 0)
		{
			tmp /= 10;
			set->cnt++;
		}
		set->cnt = set->cmp - set->cnt;
	}
}

static void	ft_value_set(t_double *num, t_set *set, int prec)
{
	int		i;

	i = set->cnt;
	if (-set->cnt >= (prec + 1))
	{
		while (-set->cnt > (prec + 1) && -(set->cnt++) >= 0)
			set->val_ul /= 10;
	}
	else
	{
		if (set->cnt > 0)
		{
			set->cnt += prec + 1;
			while (prec + 1 > 0 && (prec--) > 0)
				set->val_ul /= 10;
		}
		else
		{

		}
	}
}

void		ft_round_check_e(t_double *num, t_set *set, int prec)
{
	if (prec == 0 && set->prec_com == 0)
		prec = 6;
	ft_cnt_exp(num, set, prec);
	if (((num->frac << (prec + 1 + (num->exp - 1023))) << 12) == 0)
	{
		set->val_ul = (unsigned long long)((num->d - set->val) * \
			ft_pow(prec + set->cnt + 1));
		ft_bankers_round(set, prec);
	}
	else
	{
		set->val_ul = (unsigned long long)((num->d - set->val) * \
			ft_pow(prec + 1));
		if ((set->val_ul % 10) >= 5)
		{
			set->tmp_1 = set->val_ul;
			set->val_ul /= 10;
			set->val_ul += 1;
		}
		else
			set->val_ul /= 10;
		ft_dtoa_e(set, prec, set->val_ul);
	}
}
