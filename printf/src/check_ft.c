/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:55:39 by yjung             #+#    #+#             */
/*   Updated: 2020/10/23 22:33:57 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int		main(void)
{
//	int a = 15;
	// char *format;
	// format = format + 3;

	// int	i;
	// i = format - 1;
	char	*a;
	a = "abcde";
	int		i = 0;
	while (a[i]!= '\0')
	{
		ft_putchar_fd(a[i], 1);
		i++;
	}
	// printf("\n%d", 123);
	return (0);
}

// 정수에 precision 붙으면 남은 칸 모두 0으로? (%.10d, %10d)
// 문자열에는 precision 적용 안되는듯
// 문자열에는 width 와 [-] flag만 적용
// "%-10.5d",  -123 -> -00123
