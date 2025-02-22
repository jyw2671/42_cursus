/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:58:37 by yjung             #+#    #+#             */
/*   Updated: 2020/11/07 16:50:31 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_percent_print(t_set *set)
{
	if (set->lefted != 0 && (set->wid--) > 0)
	{
		set->len += write(1, "%", 1);
		while (set->wid > 0 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
	}
	else if (set->z_flag != 0 && set->lefted == 0)
	{
		while (set->wid > 1 && (set->wid--) > 0)
			set->len += write(1, "0", 1);
		set->len += write(1, "%", 1);
	}
	else
	{
		while (set->wid > 1 && (set->wid--) > 0)
			set->len += write(1, " ", 1);
		set->len += write(1, "%", 1);
	}
}

int			ft_check_parse(const char **format, t_set *set, va_list ap)
{
	if (set->wid > 1)
	{
		ft_percent_print(set);
		if (*(*format + 1))
			(*format)++;
	}
	else
	{
		set->len += write(1, "%", 1);
		if (*(*format + 1))
			(*format)++;
	}
	if (*(*format + 1))
		(*format)++;
	return (0);
}
