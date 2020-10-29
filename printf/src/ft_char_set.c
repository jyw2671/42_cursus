/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:32:59 by yjung             #+#    #+#             */
/*   Updated: 2020/10/29 21:24:48 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_print_char(t_set *set)
{
	if (set->lefted != 0)
	{
		write(1, &set->tmp_c, 1);
		if (set->wid > 1)
		{
			while (set->wid > 1 && (set->wid--) > 0)
				write(1, " ", 1);
		}
	}
	else
	{
		if (set->wid != 0)
		{
			while ((set->wid - 1) > 0 && (set->wid--) > 0)
				write(1, "0", 1);
			write(1, &set->tmp_c, 1);
		}
		else
			write(1, &set->tmp_c, 1);
	}
}

void			ft_char_set(t_set *set, va_list ap)
{
	set->tmp_c = (char)va_arg(ap, int);
	if (set->z_flag != 0 || set->lefted != 0)
		ft_print_char(set);
	else
	{
		if (set->wid > 1)
		{
			while (set->wid > 1 && (set->wid--) > 0)
				write(1, " ", 1);
		}
		write(1, &set->tmp_c, 1);
	}
}
