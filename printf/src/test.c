#include <stdio.h>
#include <unistd.h>
#include <limits.h>

int	main(void)
{
	// unsigned long long a = -2147483648;

	printf("%.2f", 10.135);

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
