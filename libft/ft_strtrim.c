/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:31:41 by yjung             #+#    #+#             */
/*   Updated: 2020/10/11 19:29:56 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, const char *set)
{
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	while (ft_strchr(set, s1[i]) && s1[i])
		i++;
	j = ft_strlen(s1);
	while (ft_strchr(set, s1[j]) && j != 0)
		j--;
	return (ft_substr((char *)s1, i, j + 1));
}
