/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:45:01 by yjung             #+#    #+#             */
/*   Updated: 2020/11/11 20:53:18 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_cnt_check(t_set *set)
{
	set->cmp = 0;
	set->cnt = 0;
	set->tmp_1 = set->val_ul;
	if (set->ast_p_check != 0)
		set->prec = 0;
	if (set->tmp_1 == 0)
		set->val_len += 1;
	while (set->tmp_1 != 0)
	{
		set->tmp_1 /= 10;
		set->val_len++;
	}
	if (set->val_len >= set->wid && set->val_len >= set->prec)
	{
		set->p_len = set->val_len;
		set->cnt++;
	}
	else if (set->wid > set->val_len && set->wid > set->prec)
		set->p_len = set->wid;
	else if (set->prec > set->val_len && set->prec >= set->wid)
	{
		set->p_len = set->prec;
		set->cmp++;
	}
}

static void	ft_print_sign(t_set *set)
{
	if (((set->z_flag == 0) || set->prec != 0) && (set->val_len >= set->prec))
	{
		while (((--set->p_len) - set->val_len) > 0)
			set->len += write(1, " ", 1);
	}
	else if ((set->z_flag == 0 || set->prec != 0) && (set->val_len < set->prec))
	{
		while (((--set->p_len) - set->prec) > 0)
			set->len += write(1, " ", 1);
	}
	if (set->val_sign == 1)
		set->len += write(1, "-", 1);
	else
		set->len += write(1, "+", 1);
	if (set->z_flag != 0 && set->prec == 0)
	{
		while (((--set->p_len) - set->val_len) > 0)
			set->len += write(1, "0", 1);
	}
	ft_int_print_prec(set);
	ft_int_num(set);
}

static void	ft_print_signl(t_set *set)
{
	if (set->lefted == 1)
	{
		if (set->val_sign == 1)
			set->len += write(1, "-", 1);
		else
			set->len += write(1, "+", 1);
		ft_int_print_prec(set);
		ft_int_num(set);
		while (((--set->p_len) - set->val_len) > 0)
			set->len += write(1, " ", 1);
	}
	else
		ft_print_sign(set);
}

void		ft_int_num(t_set *set)
{
	set->tmp_1 = 1;
	set->cmp = set->val_len;
	while (--set->cmp > 0)
		set->tmp_1 *= 10;
	if (set->sign == 0 && set->lefted == 0 && set->s_flag == 0 && \
	set->z_flag == 0 && set->sign_cnt != 0 && (set->val_len > set->prec))
		set->len += write(1, "-", 1);
	while (set->tmp_1 > 0)
	{
		if (set->tmp_1 < 10)
		{
			set->tmp_c = (set->val_ul / set->tmp_1) + '0';
			set->len += write(1, &set->tmp_c, 1);
			return ;
		}
		set->tmp_c = (set->val_ul / set->tmp_1) + '0';
		set->len += write(1, &set->tmp_c, 1);
		set->val_ul %= set->tmp_1;
		set->tmp_1 /= 10;
	}
}

void		ft_int_set(t_set *set)
{
	if (set->prec_com != 0 && set->prec == 0 && set->val_ul == 0)
	{
		ft_int_prec_com(set);
		return ;
	}
	ft_cnt_check(set);
	if ((set->cmp != 0) || (set->cnt != 0))
	{
		ft_int_prec_cmp(set);
		return ;
	}
	if (set->sign != 0)
		ft_print_signl(set);
	else if (set->sign == 0)
		ft_int_print(set);
}
