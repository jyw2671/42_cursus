/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 16:54:58 by yjung             #+#    #+#             */
/*   Updated: 2020/10/09 19:52:03 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	cnt;

	sign = 1;
	cnt = 0;
	while (*str == ' ' || *str == '\n' || *str == '\f' || \
			*str == '\r' || *str == '\t' || *str == '\v')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		cnt = cnt * 10 + (*str++ - '0');
	if (cnt > 9223372036854775807 && sign == 1)
		return (-1);
	else if (cnt - 1 > 9223372036854775807 && sign == -1)
		return (0);
	return (sign * cnt);
}
