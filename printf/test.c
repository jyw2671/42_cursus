#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include "libftprintf.h"

int	main(void)
{
	// printf("\n===================================\n");
	// printf("printf		: %.17f%%\n",	1.025978548534310421);
	// ft_printf("my printf	: %.17f%%",	1.025978548534310421);
	// printf("\n===================================\n");
	// printf("printf		: %.18f%%\n",	1.125978548534310421);
	// ft_printf("my printf	: %.18f",	1.125978548534310421);
	// printf("\n===================================\n");
	// printf("printf		: %.18f%%\n",	0.125978548534310421);
	// ft_printf("my printf	: %.18f",	0.125978548534310421);
	// printf("\n===================================\n");
	// printf("printf		: %.16f%%\n",	0.999999999999999900);
	// ft_printf("my printf	: %.16f",	0.999999999999999900);

	// double num = 0.0002;
	double num1 = 3.0002;
	double num2 = 123.0002;

	// t_double dnum;

	// dnum.d = 0;

	// dnum.exp = 2047;
	// dnum.frac = 1;

	double		num = 0.0002431;

	// printf("\n===================================\n");
	// printf("printf		: >% f\n",	dnum.d);
	// ft_printf("my printf	: >% f\n",	dnum.d);
	// printf("result : %d\n", num);
	// printf("\n===================================\n");
	printf("printf		: %e%%\n",	num);
	printf("printf		: %e%%\n",	num1);
	printf("printf		: %e%%\n",	num2);
	printf("printf		: %.e%%\n",	num);
	// ft_printf("my printf	: %ef",	0.09999999);

	return (0);
}

// float 처리
// 기본 출력 -> +0.000000%
//		(precision이 없을 시, width의 값과는 상관없이)
//		(width가 6보다 작아도 기본출력됨)
//
//

// 정수가 들어왔을 시
//		일단 기본출력을 출력
//		-> 그 후 precision 길이 따라 [.]이후 자릿수 정해짐
//		->flag : +다음 s_flag 먹음
//	정수가 들어오고 wid가 8이상일시
//	-> +, ' '먹고 그 다음 '-' 먹는다 마지막을 '0' 먹음
//	-> [.]이후 자릿수는 실수가 그 자릿수를 넘어가거나 precision이 6이상일때
// 의문점 +와 ' ' 상관관계 잇고 -, 0 상관관계?
//
//


// printf("%.16f",  0.999999999999999900);
//printf("%0*.*i", 2, 0, 8);
// gcc -I ../include -I ../libft/include -L ../ -lftprintf test.c

// int main()
// {
// 	char	*format = "%.50f'";
// 	char	*str_num = "2.234";
// 	double	num = 2.234;

// 	printf("\n==========================================\n");
// 	printf("result of \"%s\" for ", str); printf("\"%s\"\n", str_num);
// 	printf(str, num);
// 	printf("\n000050000100005000020000500003");
// 	printf("\n==========================================\n\n");

// 	return (0);
// }
