/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:25:35 by yjung             #+#    #+#             */
/*   Updated: 2020/11/05 22:48:29 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_z_sec(t_set *set)
{
	if (set->prec == 0)
	{
		if (set->val_sign == 1 && (set->p_len--) > 0)
			write(1, "-", 1);
		while ((set->p_len - set->val_len) > 0 && (set->p_len--) > 0)
			write(1, "0", 1);
	}
	else
	{
		if (set->val_sign == 1 && (set->p_len--) > 0)
			set->sign_cnt++;
		while ((set->p_len - set->val_len) > 0 && (set->p_len--) > 0)
			write(1, " ", 1);
		if (set->sign_cnt != 0)
			write(1, "-", 1);
	}
	ft_int_num(set);
}

static void	ft_print_z(t_set *set)
{
	if (set->prec > set->val_len)
	{
		if (set->val_sign == 1 && (set->p_len--) > 0)
			set->sign_cnt++;
		while ((set->p_len - set->prec) > 0 && (set->p_len--) > 0)
			write(1, " ", 1);
		ft_int_print_prec(set);
		ft_int_num(set);
	}
	else
		ft_print_z_sec(set);
}

static void	ft_print_sz(t_set *set)
{
	if (set->z_flag == 1 && set->prec == 0)
	{
		if (set->val_sign == 1)
			write(1, "-", 1);
		else
			write(1, " ", 1);
		set->p_len--;
		while ((set->p_len - set->val_len) > 0 && (set->p_len--) > 0)
			write(1, "0", 1);
	}
	else if ((set->z_flag == 0 || (set->z_flag == 1 && set->prec != 0)) \
	&& set->val_sign == 1 && (set->p_len--) > 0)
		set->sign_cnt++;
	if (set->z_flag == 0 || (set->z_flag == 1 && set->prec != 0))
	{
		while ((set->p_len - (set->prec > set->val_len ? set->prec : \
		set->val_len)) > 0 && (set->p_len--) > 0)
			write(1, " ", 1);
	}
	ft_int_print_prec(set);
	ft_int_num(set);
}

void		ft_int_print(t_set *set)
{
	if (set->lefted != 0)
	{
		if (set->val_sign == 1 && (set->p_len--) > 0)
			set->sign_cnt++;
		else if (set->val_sign == 0 && set->s_flag != 0 && (set->p_len--) > 0)
			write(1, " ", 1);
		ft_int_print_prec(set);
		ft_int_num(set);
		while ((set->p_len - set->val_len) > 0 && (set->p_len--) > 0)
			write(1, " ", 1);
	}
	else
	{
		if (set->s_flag != 0)
			ft_print_sz(set);
		else if (set->s_flag == 0 && set->z_flag != 0)
			ft_print_z(set);
		else if (set->s_flag == 0 && set->z_flag == 0)
			ft_print_nflag(set);
	}
}
