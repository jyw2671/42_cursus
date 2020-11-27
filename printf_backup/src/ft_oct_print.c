/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_oct_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 22:19:30 by yjung             #+#    #+#             */
/*   Updated: 2020/11/20 20:09:35 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_oct_print_zero(t_set *set)
{
	if (set->tmp_1 == 1)
	{
		set->len += write(1, "0", 1);
		return ;
	}
	else
	{
		while (set->tmp_1 > 0)
		{
			set->len += write(1, "0", 1);
			set->tmp_1 /= 8;
		}
	}
}

static int	ft_oct_print(t_set *set)
{
	if (set->tmp_2 >= 0 && set->tmp_2 < 8)
	{
		set->tmp_c = set->tmp_2 + '0';
		set->len += write(1, &set->tmp_c, 1);
	}
	if (set->val_ul == 0 && set->tmp_1 >= 1)
	{
		ft_oct_print_zero(set);
		return (1);
	}
	return (0);
}

void		ft_oct_hash_flag(t_set *set)
{
	if (set->hash != 0 && set->val_ul != 0 && set->prec == 0 && \
	set->z_flag != 0 && set->lefted == 0)
		return ;
	if (set->hash != 0 && set->val_ul != 0)
		set->len += write(1, "0", 1);
}

void		ft_oct_itoa(t_set *set)
{
	if (set->val_ul == 0)
		set->len += write(1, "0", 1);
	else
	{
		if (set->prec == 0)
			ft_oct_hash_flag(set);
		while (set->val_ul > 0)
		{
			set->tmp_2 = set->val_ul;
			set->tmp_2 /= set->tmp_1;
			set->val_ul %= set->tmp_1;
			set->tmp_1 /= 8;
			if (ft_oct_print(set) == 1)
				return ;
		}
	}
}
