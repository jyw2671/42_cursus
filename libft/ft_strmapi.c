/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 23:35:03 by yjung             #+#    #+#             */
/*   Updated: 2020/10/12 23:48:43 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL || f == NULL || ret == NULL)
		return (0);
	i = 0;
	while (i < len)
	{
		ret[i] = (*f)(i, s[i]);
		i++;
	}
	ret[len] = '\0';
	return (ret);
}
