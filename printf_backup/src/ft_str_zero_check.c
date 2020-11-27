/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_zero_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:28:00 by yjung             #+#    #+#             */
/*   Updated: 2020/11/20 02:48:38 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_null(t_set *set)
{
	while (set->wid > 0 && (set->wid--) > 0)
		set->len += write(1, " ", 1);
}

int			ft_str_zero_check(t_set *set)
{
	if (set->prec_com != 0 && set->prec == 0 && set->wid == 0)
		return (-1);
	if (set->tmp_s == 0)
	{
		set->tmp_s = "(null)";
		if (set->prec == 0 && set->prec_com != 0)
		{
			ft_print_null(set);
			return (-1);
		}
	}
	else
	{
		if (set->prec == 0 && set->prec_com != 0)
		{
			ft_print_null(set);
			return (-1);
		}
	}
	return (0);
}
