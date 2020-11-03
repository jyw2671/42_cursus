/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:31:17 by yjung             #+#    #+#             */
/*   Updated: 2020/11/03 16:05:12 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_hex_prec(t_set *set)
{
	if (set->prec < set->cnt)
		set->prec = set->cnt;
	if (set->lefted != 0)
	{
		ft_hash_flag(set);
		while ((set->prec - set->cnt) > 0 && (set->cnt++) > 0)
			write(1, "0", 1);
		ft_hex_itoa(set);
		while (((set->wid - set->prec) - set->hash) > 0 && (set->wid--) > 0)
			write(1, " ", 1);
	}
	else
	{
		while (((set->wid - set->prec) - set->hash) > 0 && (set->wid--) > 0)
			write(1, " ", 1);
		ft_hash_flag(set);
		while ((set->prec - set->cnt) > 0 && (set->cnt++) > 0)
			write(1, "0", 1);
		ft_hex_itoa(set);
	}
}

static void	ft_hex_wid(t_set *set)
{
	if (set->lefted != 0)
	{
		ft_hex_itoa(set);
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			write(1, " ", 1);
	}
	else if (set->lefted == 0 && set->z_flag != 0)
	{
		if (set->hash == 2 && set->tmp_u != 0)
		{
			if (set->hash == 2 && set->cmp == 1)
				write(1, "0x", 2);
			else if (set->hash == 2)
				write(1, "0X", 2);
		}
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			write(1, "0", 1);
		ft_hex_itoa(set);
	}
	else
	{
		while (((set->wid - set->cnt) - set->hash) > 0 && (set->wid--) > 0)
			write(1, " ", 1);
		ft_hex_itoa(set);
	}
}

void		ft_hex_set(const char **format, t_set *set, va_list ap)
{
	if ((set->tmp_u = va_arg(ap, int)) < 0)
		return ;
	if (**format == 'x')
		set->cmp = 1;
	if (set->hash != 0 && set->tmp_u == 0)
		set->hash = 0;
	ft_hex_cnt(set);
	if (set->prec_com == 1 && set->prec == 0 && set->tmp_u == 0)
	{
		while (set->wid > 0 && (set->wid--) > 0)
			write(1, " ", 1);
		return ;
	}
	if (set->prec_com == 1 || set->prec != 0)
		ft_hex_prec(set);
	else
		ft_hex_wid(set);
}
