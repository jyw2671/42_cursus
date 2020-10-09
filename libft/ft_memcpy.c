/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 16:36:06 by yjung             #+#    #+#             */
/*   Updated: 2020/10/09 16:28:19 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*n_dst;
	unsigned char	*n_src;
	size_t			i;

	n_dst = dst;
	n_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i++ < n)
		*n_dst++ = *n_src++;
	return (dst);
}
