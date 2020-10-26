/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjung <yjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 01:55:39 by yjung             #+#    #+#             */
/*   Updated: 2020/10/26 22:32:27 by yjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int		main(void)
{
//	int a = 15;
	printf("%10%%d", 3);
	return (0);
}

// 정수에 precision 붙으면 남은 칸 모두 0으로? (%.10d, %10d)
// 문자열에는 precision 적용 안되는듯
// 문자열에는 width 와 [-] flag만 적용
// "%-10.5d",  -123 -> -00123
//zero_flag 보다는 lefted가 우위
//space_flag 보다는 zero_flag가 우위
//lefted, zero_flag, space_flag 가  다 있으면 1순위 lefted, 2순위 space_flag(zero_flag는 안먹음)
