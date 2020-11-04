#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("%x", 1231233);
	// printf("%17llhd", 31111111111111);
	return (0);
}

// 모든 플래그가 있을 경우 - 먹음, wid 만큼 공백 precision 만큼 0
// [+][ ][0] 일 경우 0 먹음 wid 만큼
// 			precision 만큼 0 wid - prec 만큼 공백
// precision(precision com 인듯)이 있을 경우 - 플래그만 먹고

// precision이 없을 경우 플래그 먹는다
// [0][ ] 일 경우 0먹음
//

// 메모리 주소값은 포인터 인자로 주소를 받으신 뒤 16진수로 변환해주세요.
// libft의 putnbr_base를 활용하시면 됩니다. 저는 주소값의 비트 때문에 자료형을 고민하다가,
// slack에서 해외 멤버들의 사례를 보고 unsigned long으로 처리했습니다


// % to % 오류로 인한 재정리
// wid 1 -> % 출력
// wid > 1
//		모든 플래그 -> %를 - 후 공백 출력
//		+ 0 ' ' -> 0출력후 마지막 % 출력
//
