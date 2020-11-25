/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:06:39 by yjung             #+#    #+#             */
/*   Updated: 2020/11/25 17:07:53 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != c)
	{
		if (*s == 0)
			return (0);
		++s;
	}
	return ((char *)s);
}

char	*ft_strndup(const char *str, int n)
{
	int		i;
	char	*n_str;

	if (!(n_str = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	i = -1;
	while (++i < n)
		n_str[i] = str[i];
	n_str[i] = '\0';
	return (n_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	ret[len] = '\0';
	i = -1;
	j = ft_strlen(s1);
	while (++i < j)
		ret[i] = s1[i];
	i = -1;
	j -= 1;
	while (++j < len && ++i >= 0)
		ret[j] = s2[i];
	return (ret);
}
