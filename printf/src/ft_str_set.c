/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:15:30 by yjung             #+#    #+#             */
/*   Updated: 2020/10/29 22:20:01 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static void	ft_parse_arg(t_set *set, va_list ap)
{
	set->tmp_s = va_arg(ap, char *);
	set->val_len = ft_strlen(set->tmp_s);
}

void		ft_str_set(t_set *set, va_list ap)
{
}
