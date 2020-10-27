/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 02:25:35 by yjung             #+#    #+#             */
/*   Updated: 2020/10/28 06:28:05 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_print_left(t_set *set)
{
	if (set->val_sign == 1)
		set->p_len--;
	while (((set->p_len--) - set->val_len) > 0)
		write(1, " ", 1);
}

static void	ft_print_space(t_set *set)
{
	if (set->s_flag == 1 && set->z_flag == 0)
	{
		write(1, " ", 1);
		return ;
	}
	else if (set->s_flag == 1)
	{
		write(1, " ", 1);
		set->p_len--;
	}
	while (((set->p_len--) - set->val_len) > 0)
		write(1, "0", 1);
}

void		ft_int_print(t_set *set)
{
	if (set->lefted != 0)
	{
		if (set->p_len <= set->val_len)
			return ;
		else
			ft_print_left(set);
	}
	else
	{
		if (set->p_len <= set->val_len && set->s_flag == 1)
		{
			write(1, " ", 1);
			return ;
		}
		else if (set->p_len <= set->val_len)
			return ;
		else
			ft_print_space(set);
	}
}
