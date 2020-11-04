/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 12:43:57 by yjung             #+#    #+#             */
/*   Updated: 2020/11/04 21:06:30 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_hex_print_s(t_set *set)
{
	if (set->tmp_2 >= 0 && set->tmp_2 <= 9)
	{
		set->tmp_c = set->tmp_2 + '0';
		write(1, &set->tmp_c, 1);
	}
	else if (set->tmp_2 == 10)
		write(1, "a", 1);
	else if (set->tmp_2 == 11)
		write(1, "b", 1);
	else if (set->tmp_2 == 12)
		write(1, "c", 1);
	else if (set->tmp_2 == 13)
		write(1, "d", 1);
	else if (set->tmp_2 == 14)
		write(1, "e", 1);
	else if (set->tmp_2 == 15)
		write(1, "f", 1);
	if (set->val_ul == 0 && set->tmp_1 == 1)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

static int	ft_hex_print_l(t_set *set)
{
	if (set->tmp_2 >= 0 && set->tmp_2 <= 9)
	{
		set->tmp_c = set->tmp_2 + '0';
		write(1, &set->tmp_c, 1);
	}
	else if (set->tmp_2 == 10)
		write(1, "A", 1);
	else if (set->tmp_2 == 11)
		write(1, "B", 1);
	else if (set->tmp_2 == 12)
		write(1, "C", 1);
	else if (set->tmp_2 == 13)
		write(1, "D", 1);
	else if (set->tmp_2 == 14)
		write(1, "E", 1);
	else if (set->tmp_2 == 15)
		write(1, "F", 1);
	if (set->val_ul == 0 && set->tmp_1 == 1)
	{
		write(1, "0", 1);
		return (1);
	}
	return (0);
}

void		ft_hash_flag(t_set *set)
{
	if (set->hash == 2 && set->val_ul != 0 && set->prec == 0 && \
	set->z_flag != 0 && set->lefted == 0)
		return ;
	if (set->hash == 2 && set->val_ul != 0)
	{
		if (set->hash == 2 && set->cmp == 1)
			write(1, "0X", 2);
		else if (set->hash == 2)
			write(1, "0x", 2);
	}
}

void		ft_hex_itoa(t_set *set)
{
	if (set->val_ul == 0)
		write(1, "0", 1);
	else
	{
		if (set->prec == 0)
			ft_hash_flag(set);
		while (set->val_ul > 0)
		{
			set->tmp_2 = set->val_ul;
			set->tmp_2 /= set->tmp_1;
			set->val_ul %= set->tmp_1;
			set->tmp_1 /= 16;
			if (set->cmp == 1 && (ft_hex_print_l(set) == 1))
				return ;
			else if (set->cmp == 0 && (ft_hex_print_s(set) == 1))
				return ;
		}
	}
}
