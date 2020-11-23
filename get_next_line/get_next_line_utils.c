/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:26:19 by yjung             #+#    #+#             */
/*   Updated: 2020/11/23 22:55:16 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*n_dst;
	unsigned char	*n_src;
	size_t			i;

	n_dst = dst;
	n_src = (unsigned char *)src;
	if (dst == NULL && src == NULL)
		return (0);
	i = 0;
	while (i++ < n)
		*n_dst++ = *n_src++;
	return (dst);
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

char	*ft_strdup(const char *str, int n)
{
	int		i;
	int		size;
	char	*n_str;

	size = ft_strlen(str);
	n_str = (char *)malloc(sizeof(char) * (size + 1));
	if (n_str == NULL)
		return (0);
	i = 0;
	while (str[i] && i < n)
	{
		n_str[i] = str[i];
		i++;
	}
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
