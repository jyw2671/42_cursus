/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 22:01:33 by yjung             #+#    #+#             */
/*   Updated: 2020/10/21 18:14:28 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_parse_type(const char *format, t_set *set)
{
	size_t	i;

	if (*format == 'd' || *format == 'i' || *format == 'u')
		set->type = 'd';
	else if (*format == 's')
		set->type = 's';
	return (format);
}
