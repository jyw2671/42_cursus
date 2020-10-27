/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:58:37 by yjung             #+#    #+#             */
/*   Updated: 2020/10/27 22:32:59 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_percent_print(t_set *set)
{
	if (set->lefted != 0 && !(set->wid--))
		write(1, "%", 1);
	while (set->wid > 0)
	{
		if (set->z_flag != 0 && set->s_flag != 0 && set->lefted == 0)
		{
			while (set->wid > 1 && !(set->wid--))
				write(1, "0", 1);
			write(1, "%", 1);
		}
		else
		{
			while (set->wid > 1 && !(set->wid--))
				write(1, " ", 1);
			write(1, "%", 1);
		}
	}
}

static int	ft_check_percent(char **format, t_set *set)
{
	if (set->wid != 0)
		ft_percent_print(set);
	else if (set->wid == 0 && *((*format)++))
	{
		write(1, "%", 1);
		return (0);
	}
	return (0);
}

int			ft_check_parse(char **format, t_set *set, va_list ap)
{
	if (**format == '%')
	{
		ft_check_percent(format, set);
		return (0);
	}
}
