/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:45:01 by yjung             #+#    #+#             */
/*   Updated: 2020/10/24 17:34:20 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static size_t	*ft_cmp(t_set *set, va_list ap)
{
	size_t	i;

	if ((set->type) == 'd' || (set->type) == 'i' || (set->type) == 'u')
		return (0);
	if ((set->width) > (set->precision))
		i = (set->width);
	return (i);
}

void			ft_int_set(t_set *set, va_list ap)
{
	size_t	i;

	if ((i = ft_cmp(set, ap)) != 0)
}
