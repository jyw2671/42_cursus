/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:19:00 by yjung             #+#    #+#             */
/*   Updated: 2020/11/17 19:03:59 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_oct_prec(t_set *set)
{
	if (set->prec < set->cnt)
		set->prec = set->cnt;
	if (set->lefted != 0)
	{
		ft_oct_hash_flag(set);
		while ((set->prec - set->cnt) > 0 && (set->cnt++) > 0)
			set->len += write(1, "0", 1);
		ft_oct_itoa(set);
		while (((set->wid - set->prec) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
	}
	else
	{
		while (((set->wid - set->prec) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		ft_oct_hash_flag(set);
		while ((set->prec - set->cnt) > 0 && (set->cnt++) > 0)
			set->len += write(1, "0", 1);
		ft_oct_itoa(set);
	}
}

static void	ft_oct_wid(t_set *set)
{
	if (set->lefted != 0)
	{
		ft_oct_itoa(set);
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
	}
	else if (set->z_flag != 0 && set->prec == 0 && (set->prec_com == 0 || \
	set->ast_p_check == 1))
	{
		if (set->hash != 0 && set->val_ul != 0)
			set->len += write(1, "0", 1);
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, "0", 1);
		ft_oct_itoa(set);
	}
	else
	{
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		ft_oct_itoa(set);
	}
}

static void	ft_oct_cnt(t_set *set)
{
	set->val = set->val_ul;
	while (set->val > 0 && (set->val_len++) > -1)
		set->val /= 8;
	set->tmp_1 = 1;
	if (set->val_ul != 0)
		set->cnt = set->val_len;
	else
		set->cnt = 1;
	while ((--set->val_len) > 0)
		set->tmp_1 *= 8;
}

void		ft_oct_set(t_set *set, va_list ap)
{
	ft_print_ul(set, ap);
	if (set->hash == 2)
		set->hash = 1;
	if (set->hash != 0 && set->val_ul == 0)
		set->hash = 0;
	ft_oct_cnt(set);
	if (set->prec_com == 1 && set->prec == 0 && set->val_ul == 0)
	{
		while (set->wid > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		return ;
	}
	if (set->ast_p_check == 1)
		set->prec = 0;
	if (set->prec != 0)
		ft_oct_prec(set);
	else
		ft_oct_wid(set);
}
