/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 19:13:00 by yjung             #+#    #+#             */
/*   Updated: 2020/10/06 19:55:37 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const char *src, size_t n)
{
	unsigned char	*n_dst;
	unsigned char	*n_src;
	size_t			i;

	n_dst = (unsigned char *)dst;
	n_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	if (n_dst <= n_src)
	{
		while (i < n)
		{
			n_dst[i] = n_src[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n_dst[n - 1] = n_src[n - 1];
			n--;
		}
	}
	return (dst);
}
