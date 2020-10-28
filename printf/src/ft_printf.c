/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 18:20:05 by yjung             #+#    #+#             */
/*   Updated: 2020/10/29 04:45:21 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_rm_set(t_set *set)
{
	set->val = 0;
	set->val_sign = 0;
	set->sign_cnt = 0;
	set->val_len = 0;
	set->p_len = 0;
	set->z_flag = 0;
	set->s_flag = 0;
	set->lefted = 0;
	set->sign = 0;
	set->ast_cnt = 0;
	set->ast_p_check = 0;
	set->wid = 0;
	set->wid_cnt = 0;
	set->prec = 0;
	set->prec_cnt = 0;
	set->prec_com = 0;
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	t_set		set;

	va_start(ap, format);
	while (*format)
	{
		ft_rm_set(&set);
		while (*format && *format != '%')
			write(1, format++, 1);
		if (*format && (*format == '%') && (*(format + 1) == '%'))
			write(1, format++, 1);
		else if (*format && *(format++) == '%')
			ft_parse_printf(&format, &set, ap);
	}
	va_end(ap);
	return (0);
}
