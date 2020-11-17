/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:45:01 by yjung             #+#    #+#             */
/*   Updated: 2020/11/17 17:54:34 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_cnt_check(t_set *set)
{
	set->cmp = 0;
	set->cnt = 0;
	set->val_len = (int)ft_int_cnt(set->val_ul);
	if (set->ast_p_check != 0)
		set->prec = 0;
	if (set->val_len >= set->wid && set->val_len >= set->prec)
	{
		set->p_len = set->val_len;
		set->cnt++;
	}
	else if (set->wid > set->val_len && set->wid > set->prec)
		set->p_len = set->wid;
	else if (set->prec > set->val_len && set->prec >= set->wid)
	{
		set->p_len = set->prec;
		set->cmp++;
	}
}

static void	ft_print_lefted(t_set *set)
{
	if (set->lefted == 0 && set->z_flag != 0 && set->prec == 0 && \
	set->prec_com == 0)
	{
		ft_print_flag(set);
		while (((set->p_len) - set->val_len) > 0 && (set->p_len--) > 0)
			set->len += write(1, "0", 1);
		ft_int_num(set);
	}
	else
	{
		ft_print_flag(set);
		ft_int_print_prec(set);
		ft_int_num(set);
		while ((set->p_len - (set->prec >= set->val_len ? set->prec : \
		set->val_len)) > 0 && (set->p_len--) > 0)
			set->len += write(1, " ", 1);
	}
}

void		ft_int_num(t_set *set)
{
	set->cmp = set->val_len;
	set->tmp_s = ((char *)malloc(sizeof(char) * (set->val_len + 1)));
	set->tmp_s[set->cmp--] = '\0';
	if (set->val_ul == 0)
		set->tmp_s[set->cmp] = '0';
	while (set->val_ul > 0)
	{
		if (set->cmp > 0)
			set->tmp_s[set->cmp--] = (set->val_ul % 10) + '0';
		else
			set->tmp_s[set->cmp] = (set->val_ul % 10) + '0';
		set->val_ul /= 10;
	}
	while (set->tmp_s[set->cmp] != '\0')
		set->len += write(1, &set->tmp_s[set->cmp++], 1);
	free(set->tmp_s);
}

void		ft_int_set(t_set *set)
{
	if (set->prec_com != 0 && set->prec == 0 && set->val_ul == 0)
	{
		ft_int_prec_com(set);
		return ;
	}
	ft_cnt_check(set);
	if ((set->cmp != 0) || (set->cnt != 0))
	{
		ft_int_prec_cmp(set);
		return ;
	}
	if (set->sign != 0 || set->s_flag != 0)
		--set->p_len;
	else if (set->val_sign == 1)
		--set->p_len;
	if (set->lefted != 0)
		ft_print_lefted(set);
	else
		ft_int_print(set);
}
