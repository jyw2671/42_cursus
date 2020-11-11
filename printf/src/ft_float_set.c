/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 20:10:25 by yjung             #+#    #+#             */
/*   Updated: 2020/11/11 20:48:36 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_flag(t_set *set)
{
	if (set->sign != 0 && set->val_sign == 0)
		set->len += write(1, "+", 1);
	else if (set->val_sign != 0)
		set->len += write(1, "-", 1);
	else if (set->s_flag != 0)
		set->len += write(1, " ", 1);
}

static void	ft_float_print(t_set *set)
{
	int		i;

	i = 0;
	while (set->tmp_s[i] != '\0')
		set->len += write(1, &set->tmp_s[i++], 1);
	free(set->tmp_s);
	if (set->hash != 0 && set->prec_com != 0 && set->prec == 0)
		set->len += write(1, ".", 1);
}

static void	ft_float_z_flag(t_set *set)
{
	if (set->lefted == 0 && set->z_flag != 0)
	{
		ft_print_flag(set);
		while (((set->wid--) - set->cnt) > 0)
			set->len += write(1, "0", 1);
		ft_float_print(set);
	}
	else
	{
		while (((set->wid--) - set->cnt) > 0)
			set->len += write(1, " ", 1);
		ft_print_flag(set);
		ft_float_print(set);
	}
}

static void	ft_float_lefted(t_set *set)
{
	set->cnt = ft_strlen(set->tmp_s);
	if ((set->wid - set->cnt) > 0)
	{
		if (set->sign != 0 || set->s_flag != 0)
			set->wid--;
		else if (set->val_sign == 1)
			set->wid--;
		if (set->hash != 0 && set->prec_com != 0 && set->prec == 0)
			set->wid--;
		if (set->lefted != 0)
		{
			ft_print_flag(set);
			ft_float_print(set);
			while (((set->wid--) - set->cnt) > 0)
				set->len += write(1, " ", 1);
		}
		else
			ft_float_z_flag(set);
	}
	else
	{
		ft_print_flag(set);
		ft_float_print(set);
	}
}

void		ft_float_set(t_set *set, va_list ap)
{
	t_double	num;

	num.d = va_arg(ap, double);
	if (num.sign == 0)
		set->val_sign = 0;
	else
	{
		set->val_sign = 1;
		num.d = -num.d;
	}
	if (set->ast_p_check != 0)
	{
		set->prec = 0;
		set->prec_com = 0;
	}
	if (set->prec_com != 0 && set->prec == 0)
	{
		ft_float_z_print(set, &num);
		ft_float_lefted(set);
		return ;
	}
	set->val = (long)num.d;
	set->tmp_1 = 0;
	ft_round_check(&num, set, set->prec);
	ft_float_lefted(set);
}
