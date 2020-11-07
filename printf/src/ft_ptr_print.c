/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 18:53:57 by yjung             #+#    #+#             */
/*   Updated: 2020/11/07 16:57:34 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_ptr_print_zero(t_set *set)
{
	if (set->ptr_3 == 1)
	{
		set->len += write(1, "0", 1);
		return ;
	}
	else
	{
		while (set->ptr_3 > 0)
		{
			set->len += write(1, "0", 1);
			set->tmp_1 /= 16;
		}
	}
}

static int	ft_ptr_print_s(t_set *set)
{
	if (set->ptr_2 >= 0 && set->ptr_2 <= 9)
	{
		set->tmp_c = set->ptr_2 + '0';
		set->len += write(1, &set->tmp_c, 1);
	}
	else if (set->ptr_2 == 10)
		set->len += write(1, "a", 1);
	else if (set->ptr_2 == 11)
		set->len += write(1, "b", 1);
	else if (set->ptr_2 == 12)
		set->len += write(1, "c", 1);
	else if (set->ptr_2 == 13)
		set->len += write(1, "d", 1);
	else if (set->ptr_2 == 14)
		set->len += write(1, "e", 1);
	else if (set->ptr_2 == 15)
		set->len += write(1, "f", 1);
	if (set->ptr_1 == 0 && set->ptr_3 >= 1)
	{
		ft_ptr_print_zero(set);
		return (1);
	}
	return (0);
}

void		ft_ptr_hash_flag(t_set *set)
{
	if (set->hash == 2 && set->ptr_1 != 0)
		set->len += write(1, "0x", 2);
}

void		ft_ptr_itoa(t_set *set)
{
	if (set->ptr_1 == 0)
		set->len += write(1, "0x0", 3);
	else
	{
		while (set->ptr_1 > 0)
		{
			set->ptr_2 = set->ptr_1;
			set->ptr_2 /= set->ptr_3;
			set->ptr_1 %= set->ptr_3;
			set->ptr_3 /= 16;
			if (ft_ptr_print_s(set) == 1)
				return ;
		}
	}
}
