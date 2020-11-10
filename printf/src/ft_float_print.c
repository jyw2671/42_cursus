/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/10 19:39:28 by yjung             #+#    #+#             */
/*   Updated: 2020/11/10 22:44:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_cnt_len(t_set *set)
{
	int		len;

	if (set->val == 0)
		len = 1;
	else
	{
		while (set->val > 0)
		{
			set->val /= 10;
			len++;
		}
	}
	return (len);
}

static void	ft_dtoa_f(t_set *set, int prec, long tmp)
{
	int		len;

	len = ft_cnt_len(set);
	len += (prec + 1);
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

static void	ft_bankers_round(t_double *num, t_set *set, int prec)
{
	long	tmp;

	tmp = (long)(num->d * ft_pow(prec + 1));
	if (((tmp % 10) % 2) != 0)
	{
		tmp /= 10;
		if ((tmp % 10) > 5)
			tmp += 1;
		ft_dtoa_f(set, prec, tmp);
	}
	else
	{
		tmp /= 10;
		if ((tmp % 10) >= 5)
			tmp += 1;
		ft_dtoa_f(set, prec, tmp);
	}
}

void		ft_round_check(t_double *num, t_set *set, int prec)
{
	long	tmp;

	if (prec == 0 && set->prec_com == 0)
		prec = 6;
	if (((num->frac << (prec - 1 - (num->exp - 1023))) \
	<< 12) == 0)
		ft_bankers_round(num, set, prec);
	else
	{
		tmp = (long)((num->d * ft_pow(prec)) + 0.5);
		ft_dtoa_f(set, prec, tmp);
	}
}
