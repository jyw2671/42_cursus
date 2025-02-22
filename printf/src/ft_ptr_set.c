/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 17:03:19 by yjung             #+#    #+#             */
/*   Updated: 2020/11/16 16:55:23 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_ptr_prec(t_set *set)
{
	if (set->prec < set->cnt)
		set->prec = set->cnt;
	if (set->lefted != 0)
	{
		ft_ptr_hash_flag(set);
		while ((set->prec - set->cnt) > 0 && (set->cnt++) > 0)
			set->len += write(1, "0", 1);
		ft_ptr_itoa(set);
		while (((set->wid - set->prec) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
	}
	else
	{
		while (((set->wid - set->prec) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		ft_ptr_hash_flag(set);
		while ((set->prec - set->cnt) > 0 && (set->cnt++) > 0)
			set->len += write(1, "0", 1);
		ft_ptr_itoa(set);
	}
}

static void	ft_ptr_wid(t_set *set)
{
	if (set->lefted != 0)
	{
		ft_ptr_hash_flag(set);
		ft_ptr_itoa(set);
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
	}
	else if (set->lefted == 0 && set->z_flag != 0)
	{
		if (set->hash == 2 && set->val_ul != 0)
			set->len += write(1, "0x", 2);
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, "0", 1);
		ft_ptr_itoa(set);
	}
	else
	{
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		ft_ptr_hash_flag(set);
		ft_ptr_itoa(set);
	}
}

static void	ft_ptr_cnt(t_set *set)
{
	set->tmp_2 = set->val_ul;
	while (set->tmp_2 > 0)
	{
		set->tmp_2 /= 16;
		set->val_len++;
	}
	set->tmp_1 = 1;
	if (set->val_ul != 0)
		set->cnt = set->val_len;
	else
		set->cnt = 1;
	while ((--set->val_len) > 0)
		set->tmp_1 *= 16;
}

void		ft_ptr_set(t_set *set, va_list ap)
{
	set->val_ul = (unsigned long long)va_arg(ap, void *);
	set->hash = 2;
	ft_ptr_cnt(set);
	if (set->prec_com == 1 && set->prec == 0 && set->val_ul == 0)
	{
		while (set->wid > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		return ;
	}
	if (set->ast_p_check != 0)
		set->prec = 0;
	if (set->prec_com == 1 || set->prec != 0)
		ft_ptr_prec(set);
	else
	{
		ft_ptr_wid(set);
	}
}
