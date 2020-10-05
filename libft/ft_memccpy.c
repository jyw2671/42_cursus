/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 21:15:27 by yjung             #+#    #+#             */
/*   Updated: 2020/10/06 00:10:35 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*n_dst;
	unsigned char	*n_src;
	size_t			i;

	n_dst = dst;
	n_src = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		n_dst[i] = n_src[i];
		if (n_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
