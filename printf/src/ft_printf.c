/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:20:05 by yjung             #+#    #+#             */
/*   Updated: 2020/10/24 22:21:50 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_set		set;

	va_start(ap, format);
	while (*format)
	{
		while (*format != '%')
			write(1, format++, 1);
		if ((*format == '%') && (*(format + 1) == '%'))
		{
			write(1, format, 1);
			format++;
		}
		else
			ft_parse_printf(&format, &set, ap);
	}
	va_end(ap);
	return (0);
}
