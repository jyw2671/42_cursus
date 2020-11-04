/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:15:30 by yjung             #+#    #+#             */
/*   Updated: 2020/11/04 21:37:46 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_str_flag(t_set *set)
{
	if (set->lefted != 0)
	{
		while (set->cmp < set->tmp_1)
			write(1, &set->tmp_s[set->cmp++], 1);
		while ((set->cnt - set->tmp_1) > 0 && (set->cnt--) > 0)
			write(1, " ", 1);
	}
	else if (set->lefted == 0 && set->z_flag != 0)
	{
		while ((set->cnt - set->tmp_1) > 0 && (set->cnt--) > 0)
			write(1, "0", 1);
		while (set->cmp < set->tmp_1)
			write(1, &set->tmp_s[set->cmp++], 1);
	}
}

static void	ft_str_wid(t_set *set)
{
	set->cmp = 0;
	if (set->lefted != 0 || set->z_flag != 0)
	{
		set->tmp_1 = set->val_len;
		set->cnt = set->wid;
		ft_str_flag(set);
	}
	else
	{
		while ((set->wid - set->val_len) > 0 && (set->wid--) > 0)
			write(1, " ", 1);
		while (set->cmp < set->val_len)
			write(1, &set->tmp_s[set->cmp++], 1);
	}
}

static void	ft_str_val_len(t_set *set)
{
	set->cmp = 0;
	set->tmp_1 = set->prec;
	if (set->wid > set->tmp_1)
		set->cnt = set->wid;
	else
		set->cnt = set->tmp_1;
	if (set->lefted != 0 || set->z_flag != 0)
		ft_str_flag(set);
	else
	{
		while ((set->cnt - set->tmp_1) > 0 && (set->cnt--) > 0)
			write(1, " ", 1);
		while (set->cmp < set->tmp_1)
			write(1, &set->tmp_s[set->cmp++], 1);
	}
}

static void	ft_str_prec(t_set *set)
{
	set->cmp = 0;
	set->tmp_1 = set->val_len;
	if (set->wid > set->tmp_1)
		set->cnt = set->wid;
	else
		set->cnt = set->tmp_1;
	if (set->lefted != 0 || set->z_flag != 0)
		ft_str_flag(set);
	else
	{
		while ((set->cnt - set->tmp_1) > 0 && (set->cnt--) > 0)
			write(1, " ", 1);
		while (set->cmp < set->tmp_1)
			write(1, &set->tmp_s[set->cmp++], 1);
	}
}

void		ft_str_set(t_set *set, va_list ap)
{
	set->tmp_s = va_arg(ap, char *);
	if (ft_str_zero_check(set) == -1)
		return ;
	set->val_len = ft_strlen(set->tmp_s);
	if (set->prec <= set->val_len && set->prec != 0)
		ft_str_val_len(set);
	else if (set->prec > set->val_len && set->prec != 0)
		ft_str_prec(set);
	else if (set->prec == 0 && set->val_len < set->wid)
		ft_str_wid(set);
	else
	{
		set->cmp = 0;
		set->tmp_1 = set->val_len;
		while (set->cmp < set->tmp_1)
			write(1, &set->tmp_s[set->cmp++], 1);
	}
}
