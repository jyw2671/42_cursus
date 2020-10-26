/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 19:58:37 by yjung             #+#    #+#             */
/*   Updated: 2020/10/26 22:57:36 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_check_percent(t_set *set, va_list ap)
{
	if (set->lefted != 0 && !(set->ptr_w--))
		write(1, "%", 1);
	while (set->ptr_w > 0)
	{
		if (set->z_flag != 0 && set->s_flag != 0 && set->lefted == 0)
		{
			while (set->ptr_w > 1 && !(set->ptr_w--))
				write(1, "0", 1);
			write(1, "%", 1);
		}
		else
		{
			while (set->ptr_w > 1 && !(set->ptr_w--))
				write(1, " ", 1);
			write(1, "%", 1);
		}
	}
}

int			ft_check_parse(char **format, t_set *set, va_list ap)
{
	if (**format == '*')
		return (-1);
	else if (**format == '%' && set->ptr_w != 0)
		ft_check_percent(set, ap);
	else if (**format == '%' && set->ptr_w == 0 && *((*format)++))
	{
		write(1, "%", 1);
		return (0);
	}
}
