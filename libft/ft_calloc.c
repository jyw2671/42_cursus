/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 16:55:49 by yjung             #+#    #+#             */
/*   Updated: 2020/10/09 21:34:17 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t cnt, size_t size)
{
	char	*ret;
	size_t	i;

	ret = (char *)malloc(size * cnt);
	if (ret == NULL)
		return (0);
	i = -1;
	while (++i < size * cnt)
		ret[i] = 0;
	return ((void *)ret);
}
