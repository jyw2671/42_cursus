/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_e_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 17:05:42 by yjung             #+#    #+#             */
/*   Updated: 2020/11/20 02:57:27 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_e_print(t_set *set)
{
	int		i;

	i = 0;
	while (set->tmp_s[i] != '\0')
		set->len += write(1, &set->tmp_s[i++], 1);
	free(set->tmp_s);
}

static void	ft_e_z_flag(t_set *set)
{
	if (set->lefted == 0 && set->z_flag != 0)
	{
		ft_print_flag(set);
		while (((set->wid--) - set->cnt) > 0)
			set->len += write(1, "0", 1);
		ft_e_print(set);
	}
	else
	{
		while (((set->wid--) - set->cnt) > 0)
			set->len += write(1, " ", 1);
		ft_print_flag(set);
		ft_e_print(set);
	}
}

static void	ft_e_lefted(t_set *set)
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
			ft_e_print(set);
			while (((set->wid--) - set->cnt) > 0)
				set->len += write(1, " ", 1);
		}
		else
			ft_e_z_flag(set);
	}
	else
	{
		ft_print_flag(set);
		ft_e_print(set);
	}
}

static void	ft_e_z_print(t_set *set, t_double *num, int len)
{
	set->tmp_s = ((char *)malloc(sizeof(char) * (len + 1)));
	set->tmp_s[len--] = '\0';
	ft_dtoa_e_print(set, 0, len);
	len -= 4;
	while (len > 1)
		set->tmp_s[len--] = '0';
	if (set->prec != 0 || set->hash != 0)
		set->tmp_s[len--] = '.';
	set->tmp_s[len] = '0';
	ft_e_lefted(set);
}

void		ft_e_set(t_set *set, va_list ap)
{
	t_double	num;

	num.d1.d = va_arg(ap, double);
	if (ft_nan_inf_print(set, &num) == -1)
		return ;
	if (set->ast_p_check != 0)
	{
		set->prec = 0;
		set->prec_com = 0;
	}
	if (num.d1.d == 0)
	{
		if (set->prec == 0 && set->prec_com == 0)
			set->prec = 6;
		if (set->prec != 0 || set->hash != 0)
			set->cnt = (set->prec + 6);
		else
			set->cnt = 5;
		ft_e_z_print(set, &num, set->cnt);
		return ;
	}
	set->val = (long long)num.d1.d;
	set->tmp_1 = 0;
	ft_round_check_e(&num, set, set->prec);
	ft_e_lefted(set);
}
