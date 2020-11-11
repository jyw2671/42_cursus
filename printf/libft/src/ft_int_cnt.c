/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_cnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 14:27:22 by yjung             #+#    #+#             */
/*   Updated: 2020/11/11 22:40:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long long	ft_int_cnt(unsigned long long num)
{
	unsigned long long	len;

	if (num == 0)
		len = 1;
	else
	{
		len = 0;
		while (num > 0)
		{
			num /= 10;
			len++;
		}
	}
	return (len);
}
