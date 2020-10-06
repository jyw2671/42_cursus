/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 20:47:51 by yjung             #+#    #+#             */
/*   Updated: 2020/10/06 21:04:38 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *a1, const void *a2, size_t n)
{
	unsigned char	*n_a1;
	unsigned char	*n_a2;
	size_t			i;

	n_a1 = (unsigned char *)a1;
	n_a2 = (unsigned char *)a2;
	i = 0;
	while (i < n)
	{
		if (n_a1[i] != n_a2[i])
			return (n_a1[i] - n_a2[i]);
		i++;
	}
	return (0);
}
