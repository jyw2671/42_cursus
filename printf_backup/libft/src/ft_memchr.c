/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:05:15 by yjung             #+#    #+#             */
/*   Updated: 2020/10/06 21:11:05 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int cmp, size_t n)
{
	unsigned char	*n_ptr;
	size_t			i;

	n_ptr = (unsigned char *)ptr;
	i = 0;
	while (i < n)
	{
		if (n_ptr[i] == (unsigned char)cmp)
			return ((void *)&n_ptr[i]);
		i++;
	}
	return (0);
}
