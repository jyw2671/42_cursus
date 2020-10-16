/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:20:05 by yjung             #+#    #+#             */
/*   Updated: 2020/10/16 22:11:42 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		num;

	va_start(ap, format);
	num = ft_print(0, format, ap);
	va_end(ap);
	return (num);
}
