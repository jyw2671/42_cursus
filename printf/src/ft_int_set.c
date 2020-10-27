/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:45:01 by yjung             #+#    #+#             */
/*   Updated: 2020/10/28 06:23:33 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_num(t_set *set)
{
	if (set->sign == 0 && set->lefted != 0)
		return ;
	if (set->val_sign == 1)
	{
		if (set->lefted == 1 && set->sign == 0)
			write(1, "-", 1);
		while (set->val > 0)
		{
			set->tmp_c = set->val % 10 + '0';
			write(1, &set->tmp_c, 1);
			set->val /= 10;
		}
	}
	else
	{
		while (set->val > 0)
		{
			set->tmp_c = set->val % 10 + '0';
			write(1, &set->tmp_c, 1);
			set->val /= 10;
		}
	}
}

static void	ft_cnt_check(t_set *set)
{
	set->tmp_i = 0;
	if (set->wid == -1)
		set->wid = set->wid_cnt;
	else if (set->prec == -1)
		set->prec = set->prec_cnt;
	set->val_tmp = set->val;
	while (set->val_tmp > 0)
	{
		set->val_tmp /= 10;
		set->val_len++;
	}
	if (set->val_len >= set->wid && set->val_len >= set->prec_cnt)
		set->p_len = set->val_len;
	else if (set->wid > set->val_len && set->wid_cnt > set->prec_cnt)
		set->p_len = set->wid_cnt;
	else if (set->prec_cnt > set->val_len && set->prec_cnt >= set->wid_cnt)
	{
		set->p_len = set->prec_cnt;
		set->tmp_i++;
	}
}

static void	ft_print_sign(t_set *set)
{
	if (set->z_flag == 0 && set->s_flag == 1)
	{
		if (set->val_sign == 1)
		{
			while (((--set->p_len) - set->val_len) > 0)
				write(1, " ", 1);
			write(1, "-", 1);
			ft_print_num(set);
		}
		else
		{
			while ((set->p_len - set->val_len) > 0)
				write(1, " ", 1);
			ft_print_num(set);
		}
	}
}

static void	ft_print_signl(t_set *set)
{
	if (set->lefted == 1)
	{
		if (set->val_sign == 1)
			write(1, "-", 1);
		else
			write(1, "+", 1);
		ft_print_num(set);
		while (((--set->p_len) - set->val_len) > 0)
			write(1, " ", 1);
	}
	else
		ft_print_sign(set);
}

void		ft_int_set(t_set *set, va_list ap)
{
	if ((set->val = va_arg(ap, int)) < 0 && set->val_sign++ == 0)
		set->val = -set->val;
	ft_cnt_check(set);
	if (set->tmp_i != 0)
	{
		if (set->val_sign == 1)
			write(1, "-", 1);
		else if (set->sign != 0 && set->val_sign == 0)
			write(1, "+", 1);
		else if (set->s_flag != 0 && set->sign == 0 && set->val_sign == 0)
			write(1, " ", 1);
		while (((set->p_len--) - set->val_len) > 0)
			write(1, "0", 1);
		ft_print_num(set);
		return ;
	}
	if (set->sign != 0)
		ft_print_signl(set);
	else if (set->sign == 0)
	{
		if (set->lefted != 0)
			ft_print_num(set);
		ft_int_print(set);
		ft_print_num(set);
	}
}
