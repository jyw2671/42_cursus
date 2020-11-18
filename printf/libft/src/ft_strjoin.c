/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 14:57:01 by yjung             #+#    #+#             */
/*   Updated: 2020/11/19 02:05:08 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (0);
	i = 0;
	j = 0;
	while (j < ft_strlen(s1))
		ret[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		ret[i++] = s2[j++];
	ret[len] = '\0';
	return (ret);
}
