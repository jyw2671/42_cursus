/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 18:31:41 by yjung             #+#    #+#             */
/*   Updated: 2021/03/22 20:43:59 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, const char *set)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (s1 == NULL || set == NULL)
		return (0);
	i = 0;
	j = ft_strlen(s1);
	if (j == 0)
		return (ft_strdup(""));
	while (i < j && ft_strchr(set, s1[i]))
		i++;
	j--;
	while (j >= i && ft_strchr(set, s1[j]))
		j--;
	ret = ft_substr(s1, i, j - i + 1);
	return (ret);
}
