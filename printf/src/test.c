#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	// int x = 256;
	// x /= 16;
	// printf("%d", x);
	printf("%x", 43);
	return (0);
}


// 모든 플래그가 있을 경우 - 먹음, wid 만큼 공백 precision 만큼 0
// [+][ ][0] 일 경우 0 먹음 wid 만큼
// 			precision 만큼 0 wid - prec 만큼 공백
// precision(precision com 인듯)이 있을 경우 - 플래그만 먹고

// precision이 없을 경우 플래그 먹는다
// [0][ ] 일 경우 0먹음
//
