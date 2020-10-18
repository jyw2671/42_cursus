/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:20:05 by yjung             #+#    #+#             */
/*   Updated: 2020/10/18 22:11:38 by yjung            ###   ########.fr       */
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
		if (*format != '%')
			write(1, format++, 1);
		else if ((*format == '%') && (*(format + 1) == '%'))
		{
			write(1, format, 1);
			format++;
		}
		else
			ft_parse_printf(format, &set);
	}
	va_end(ap);
	return (0);
}
