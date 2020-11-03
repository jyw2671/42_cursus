/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_zero_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 19:28:00 by yjung             #+#    #+#             */
/*   Updated: 2020/11/03 16:05:16 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_null(t_set *set)
{
	while (set->wid > 0 && (set->wid--) > 0)
		write(1, " ", 1);
}

int		ft_str_zero_check(t_set *set)
{
	if (set->tmp_s != 0 && set->prec_com != 0 && \
	set->prec == 0 && set->wid == 0)
		return (-1);
	if (set->tmp_s == 0)
	{
		set->tmp_s = "(null)";
		if (set->ast_p_check == 1)
			set->prec = 0;
		else if (set->ast_p_check == 0 && set->prec == 0 && set->prec_com != 0)
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
