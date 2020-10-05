/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 17:06:48 by yjung             #+#    #+#             */
/*   Updated: 2020/10/01 18:53:54 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;
	size_t	slen;

	ret = 0;
	slen = ft_strlen(s);
	if (c == 0)
		return ((char *)s);
	while (slen != 0 && *(s + slen) != c)
		slen--;
	if (*(s + slen) == c)
		ret = (char *)s;
	return (ret);
}
