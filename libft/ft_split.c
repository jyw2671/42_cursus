/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:16:30 by yjung             #+#    #+#             */
/*   Updated: 2020/10/13 21:45:06 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cutter(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		cnt++;
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	return (cnt);
}

static size_t	ft_len(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s && *s != c)
	{
		s++;
		len++;
	}
	return (len);
}

static char		*ft_strdup_len(const char *s, size_t len)
{
	size_t	i;
	char	*ret;

	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (ret == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = 0;
	return (ret);
}

static void		ft_free_arr(char **s, int i)
{
	while (i--)
		free(s[i]);
	free(s);
}

char			**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	cnt;
	size_t	len;
	size_t	i;

	cnt = ft_cutter(s, c);
	ret = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (ret == NULL)
		return (0);
	i = 0;
	while (i < cnt)
	{
		while (*s && *s == c)
			s++;
		len = ft_len(s, c);
		if ((ret[i] = ft_strdup_len(s, len)) == NULL)
		{
			ft_free_arr(ret, i - 1);
			return (0);
		}
		s += len;
		i++;
	}
	ret[cnt] = 0;
	return (ret);
}
