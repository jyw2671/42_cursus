/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 14:45:01 by yjung             #+#    #+#             */
/*   Updated: 2020/10/21 18:24:25 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

// static void		ft_free_arr(char **s, int i)
// {
// 	while (i--)
// 		free(s[i]);
// 	free(s);
// }

static size_t	*ft_cmp(t_set *set)
{
	size_t	i;

	if (set.type == 'd' || set.type == 'i' || set.type == 'u')
		return (0);
	if (set.width > set.precision)
		i = set.width;
	return (i);
}

char			*ft_int_set(const char *format, t_set *set)
{
	if (ft_cmp(&set) != 0)
}
