/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:16:30 by yjung             #+#    #+#             */
/*   Updated: 2020/10/13 03:28:46 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(const char *s, char c)
{
	size_t	cnt;

	cnt = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			cnt++;
			while (*s != '\0' && *s != c)
				s++;
		}
	}
	return (cnt);
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

	cnt = ft_cnt(s, c);
	ret = (char **)malloc(sizeof(char) * (cnt + 1));
	if (ret == NULL)
		return (0);
	i = 0;
	while (i < cnt)
	{

	}
}
