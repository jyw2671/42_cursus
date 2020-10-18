/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 02:16:39 by yjung             #+#    #+#             */
/*   Updated: 2020/10/19 02:24:51 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

size_t	ft_parse_num(const char *format)
{
	size_t	i;

	i = 0;
	while (*format != '.' && *format <= '0' && *format >= '9')
		i = i * 10 + (*format++ - '0');
	if (ft_strchr(format, '.'))
	{
		format++;
		while (*format <= '0' && *format >= '9')
			i = i * 10 + (*format++ - '0');
	}
	return (i);
}
