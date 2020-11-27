#include <stdio.h>
#include "libftprintf.h"
#include <limits.h>

int		main(void)
{
	printf("%#g\n", 12345.3);
	printf("%#g\n", 0.0000123);
	printf("%#g", 0.0001234);
	// ft_printf("%g", 1.3);
	return (0);
}

// f or e?
// → 뒤에있는 0을 무조건 없애준다..?
// → # 있으면 0 안없애도 됨.
// 	→ 어떨때 f..?
// 	→ 10진 exp 기준 → -4보다 작거나 or prec보다 같거나 클때에는 e로
// 	→ 아니라면 f
