/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:34:29 by yjung             #+#    #+#             */
/*   Updated: 2020/10/05 23:43:47 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l_len;

	l_len = ft_strlen(little);
	if (little == NULL)
		return ((char *)big);
	if (big == NULL || l_len > len)
		return (0);
	i = -1;
	while (++i < len && big[i])
	{
		j = 0;
		if (big[i] == little[j])
		{
			while (++j < l_len)
			{
				if (big[i + j] != little[j])
					break ;
				if ((j + 1) == l_len)
					return ((char *)&big[i]);
			}
		}
	}
	return (0);
}
