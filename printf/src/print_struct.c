/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:19:57 by yjung             #+#    #+#             */
/*   Updated: 2020/11/03 16:05:14 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	print_sturct(t_set *set)
{
	printf("z_flag			: %d\n", set->z_flag);
	printf("s_flag			: %d\n", set->s_flag);
	printf("lefted			: %d\n", set->lefted);
	printf("sign			: %d\n", set->sign);
	printf("wid				: %d\n", set->wid);
	printf("prec			: %d\n", set->prec);
	printf("val				: %d\n", set->val);
	printf("val_len			: %d\n", set->val_len);
	printf("p_len			: %d\n", set->p_len);
	printf("val_sign		: %d\n", set->val_sign);
}
