/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 00:13:40 by yjung             #+#    #+#             */
/*   Updated: 2020/10/13 02:26:08 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt_digit(int n)
{
	size_t	cnt;

	cnt = 0;
	while (n)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

char			*ft_itoa(int n)
{
	unsigned int	nbr;
	char			*ret;
	size_t			len;
	size_t			sign;

	if (n == 0)
		return (ft_strdup("0"));
	len = ft_cnt_digit(n);
	sign = (n >= 0) ? 0 : 1;
	nbr = (n < 0) ? -n : n;
	ret = (char *)malloc(sizeof(char) * (sign + len + 1));
	if (ret == NULL)
		return (0);
	if (sign == 1)
		ret[0] = '-';
	ret[sign + len--] = '\0';
	while (nbr > 0)
	{
		ret[sign + len--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (ret);
}
