/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 21:33:04 by yjung             #+#    #+#             */
/*   Updated: 2020/11/16 23:01:13 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t n)
{
	unsigned char	*n_dst;
	size_t			i;

	n_dst = (unsigned char *)dst;
	i = 0;
	while (i < n)
	{
		n_dst[i] = (unsigned char)c;
		++i;
	}
	return (dst);
}
