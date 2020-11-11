/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_third.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 03:36:29 by yjung             #+#    #+#             */
/*   Updated: 2020/11/11 22:40:19 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_int_print_prec(t_set *set)
{
	if (set->sign_cnt != 0)
		set->len += write(1, "-", 1);
	if (set->prec > set->val_len && ((set->wid - set->val_len) > 0))
	{
		while ((set->prec - set->val_len) > 0)
		{
			set->len += write(1, "0", 1);
			set->prec--;
			set->p_len--;
		}
	}
}

void		ft_print_nflag(t_set *set)
{
	if (set->val_sign == 1 && (set->p_len--) > 0)
		set->sign_cnt++;
	if (set->prec > set->val_len)
	{
		while ((set->p_len - set->prec) > 0 && (set->p_len--) > 0)
			set->len += write(1, " ", 1);
		ft_int_print_prec(set);
	}
	else
	{
		while ((set->p_len - set->val_len) > 0 && (set->p_len--) > 0)
			set->len += write(1, " ", 1);
	}
	ft_int_num(set);
}

void		ft_int_prec_cmp(t_set *set)
{
	if (set->cmp != 0 || set->cnt != 0)
	{
		if ((set->sign != 0 && set->val_sign != 0) || set->val_sign != 0)
			set->len += write(1, "-", 1);
		else if (set->sign != 0 && set->val_sign == 0)
			set->len += write(1, "+", 1);
		else if (set->sign == 0 && set->s_flag != 0)
			set->len += write(1, " ", 1);
		while ((set->p_len--) - set->val_len > 0)
			set->len += write(1, "0", 1);
		ft_int_num(set);
	}
}

void		ft_int_prec_com(t_set *set)
{
	if (set->prec_com != 0 && set->prec == 0 && set->val_ul == 0)
	{
		if (set->lefted != 0 && set->sign != 0)
		{
			set->len += write(1, "+", 1);
			if ((set->wid--) == 0)
				return ;
		}
		if (set->lefted == 0 && set->sign != 0)
			set->wid--;
		while ((set->wid--) > 0)
			set->len += write(1, " ", 1);
		if (set->lefted == 0 && set->sign != 0)
			set->len += write(1, "+", 1);
	}
}
