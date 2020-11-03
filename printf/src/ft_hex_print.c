/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:43:57 by yjung             #+#    #+#             */
/*   Updated: 2020/11/03 16:05:15 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_hex_print_s(t_set *set)
{
	if (set->val >= 0 && set->val <= 9)
	{
		set->tmp_c = set->val + '0';
		write(1, &set->tmp_c, 1);
	}
	else if (set->val == 10)
		write(1, "a", 1);
	else if (set->val == 11)
		write(1, "b", 1);
	else if (set->val == 12)
		write(1, "c", 1);
	else if (set->val == 13)
		write(1, "d", 1);
	else if (set->val == 14)
		write(1, "e", 1);
	else if (set->val == 15)
		write(1, "f", 1);
}

static void	ft_hex_print_l(t_set *set)
{
	if (set->val >= 0 && set->val <= 9)
	{
		set->tmp_c = set->val + '0';
		write(1, &set->tmp_c, 1);
	}
	else if (set->val == 10)
		write(1, "A", 1);
	else if (set->val == 11)
		write(1, "B", 1);
	else if (set->val == 12)
		write(1, "C", 1);
	else if (set->val == 13)
		write(1, "D", 1);
	else if (set->val == 14)
		write(1, "E", 1);
	else if (set->val == 15)
		write(1, "F", 1);
}

void		ft_hex_cnt(t_set *set)
{
	set->val = set->tmp_u;
	while (set->val > 0 && (set->val_len++) > -1)
		set->val /= 16;
	set->tmp_u1 = 1;
	if (set->tmp_u != 0)
		set->cnt = set->val_len;
	else
		set->cnt = 1;
	while ((--set->val_len) > 0)
		set->tmp_u1 *= 16;
}

void		ft_hash_flag(t_set *set)
{
	if (set->hash == 2 && set->tmp_u != 0 && set->prec == 0 && \
	set->z_flag != 0 && set->lefted == 0)
		return ;
	if (set->hash == 2 && set->tmp_u != 0)
	{
		if (set->hash == 2 && set->cmp == 1)
			write(1, "0x", 2);
		else if (set->hash == 2)
			write(1, "0X", 2);
	}
}

void		ft_hex_itoa(t_set *set)
{
	if (set->tmp_u == 0)
		write(1, "0", 1);
	else
	{
		if (set->prec == 0)
			ft_hash_flag(set);
		while (set->tmp_u > 0)
		{
			set->val = set->tmp_u;
			set->val /= set->tmp_u1;
			set->tmp_u %= set->tmp_u1;
			set->tmp_u1 /= 16;
			if (set->cmp == 1)
				ft_hex_print_s(set);
			else
				ft_hex_print_l(set);
		}
	}
}
