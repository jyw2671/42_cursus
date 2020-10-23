/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/23 19:03:07 by yjung             #+#    #+#             */
/*   Updated: 2020/10/23 22:33:52 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_type_printf(t_set *set, va_list ap)
{
	if ((set->type) == 'd')
		ft_int_set(&set, ap);
	if ((set->type) == 'c')
		ft_char_set(&set, ap);
	if ((set->type) == 's')
		ft_str_set(&set, ap);
}
