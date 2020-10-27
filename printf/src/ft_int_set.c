/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:45:01 by yjung             #+#    #+#             */
/*   Updated: 2020/10/27 22:32:59 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_num(t_set *set)
{
	if (set->val_sign == 1)
	{
		if(set->lefted == 0)
			write(1, "-", 1);
		while (set->val > 0)
		{
			set->tmp_c = set->val % 10 + '0';
			write(1, set->tmp_c, 1);
			set->val /= 10;
		}
	}
	else
	{
		while (set->val > 0)
			{
				set->tmp_c = set->val % 10 + '0';
				write(1, set->tmp_c, 1);
				set->val /= 10;
			}
	}
}

static void	ft_check_parse(t_set *set)
{
	if (set->wid == -1)
		set->wid =set->wid_cnt;
	else if (set->prec == -1)
		set->prec =set->prec_cnt;
	set->val_len = ft_strlen(set->val);
	if (set->val_len >= set->wid && set->val_len >= set->prec_cnt)
		set->p_len = set->val_len;
	else if (set->wid > set->val_len && set->wid_cnt > set->prec_cnt)
		set->p_len = set->wid_cnt;
	else if (set->prec_cnt > set->val_len && set->prec_cnt > set->wid_cnt)
		set->p_len = set->prec_cnt;
}

static void	ft_print_sign_left(t_set *set)
{
	if (set->sign != 0 && set->p_len < set->val_len)
	{
		if (set->sign != 0 && set->val >= 0)
			write(1, "+", 1);
		else if (set->sign != 0 && set->val < 0)
			write(1, "-", 1);
	}

}

void		ft_int_set(t_set *set, va_list ap)
{
	if ((set->val = va_arg(ap, int)) < 0 && set->val_sign++ == 0)
		set->val = -set->val;
	ft_check_parse(set);
	ft_print_sign_left(set);
}

// *가 존재시 .*, * 여부 검사 후 길이 비교
// *, .* 둘다 존재시 리턴	wid, ast_w 둘다 존재시 리턴	prec, ast_p 둘다 존재시 리턴 처리 함
