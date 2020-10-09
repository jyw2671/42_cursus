/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/09 21:41:33 by yjung             #+#    #+#             */
/*   Updated: 2020/10/10 02:16:24 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s == NULL)
		return (0);
	if (ft_strlen(s) < start)
		return (ft_strdup("\0"));
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (0);
	i = 0;
	while (i < len && s[start + i])
	{
		ret[i] = s[start + i];
		i++;
	}
	return (ret);
}
