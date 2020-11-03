/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:53:57 by yjung             #+#    #+#             */
/*   Updated: 2020/11/03 23:11:08 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_ptr_print_s(t_set *set)
{
	if (set->tmp_ul >= 0 && set->tmp_ul <= 9)
	{
		set->tmp_c = set->tmp_ul + '0';
		write(1, &set->tmp_c, 1);
	}
	else if (set->tmp_ul == 10)
		write(1, "a", 1);
	else if (set->tmp_ul == 11)
		write(1, "b", 1);
	else if (set->tmp_ul == 12)
		write(1, "c", 1);
	else if (set->tmp_ul == 13)
		write(1, "d", 1);
	else if (set->tmp_ul == 14)
		write(1, "e", 1);
	else if (set->tmp_ul == 15)
		write(1, "f", 1);
}

void		ft_ptr_hash_flag(t_set *set)
{
	if (set->hash == 2 && set->val_ul != 0)
		write(1, "0x", 2);
}

void		ft_ptr_itoa(t_set *set)
{
	if (set->val_ul == 0)
		write(1, "0x0", 3);
	else
	{
		while (set->val_ul > 0)
		{
			set->tmp_ul = set->val_ul;
			set->tmp_ul /= set->tmp_ul1;
			set->val_ul %= set->tmp_ul1;
			set->tmp_ul1 /= 16;
			ft_ptr_print_s(set);
		}
	}
}
