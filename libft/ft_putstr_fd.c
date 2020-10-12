/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 20:33:14 by yjung             #+#    #+#             */
/*   Updated: 2020/10/12 20:42:50 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	int		idx;

	idx = 0;
	if (s == NULL)
		return ;
	while (s[idx] != '\0')
	{
		ft_putchar_fd(s[idx], fd);
		idx++;
	}
}
