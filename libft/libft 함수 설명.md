- ft_strlcpy
size_t ft_strlcpy(char *dst, const char *src, size_t size)
src에서 dst로 값을 복사하는데 size길이 만큼 한다. 여기서 size는 문자열 끝의 NULL 까지 포함한 길이를 넣어줘야한다.
반환값 -> dst 길이 값(복사되어진 데이터의 길이이므로 NULL은 빠진다)(size - 1)
	printf("%lu\n", ft_strlcpy(dst, src, 5));
	printf("%s\n", dst);

- ft_strlcat
dst의 기존 데이터에 src 데이터를 붙여 넣는다. size 만큼
size = dst 길이 + 붙일 데이터 길이 + NULL 값을 넣어야 한다.
dst 길이보다 작으면 src 데이터가 넣어지진 않는다.
즉, size는 dst 길이 + NULL 길이보다 클 때부터 src 데이터가 들어간다.

- ft_strchr
char	*ft_strchr(const char *s, int c);
<string.h> lib 속의 함수
입력은 const char로 받고 반환값은 char 이므로 return ((char *)s)
이 함수는 문자열에서 문자를 검색할 때 사용하는 함수이다.
s에 문자열을 넣고 c에는 찾을 문자를 넣어
s에서 c의 문자를 찾는 것이다.
이 값은 찾은 c의 문자의 주소 값을 반환한다.
만약 찾지 못했다면 NULL 값을 반환한다.
* 이때 마지막 NULL 문자도 c 문자열의 일부로 간주하기 때문에 이 함수는 문자열의 맨 끝 부분을 가리키는 포인터를 얻기 위해 사용할 수 도 있다.

- ft_strrchr
char *ft_strrchr(const char *s, int c)
이 함수는 strchr 함수랑 같지만 다른 점은 문자열에서 문자를 검색하되 가장 마지막으로 나타나는 위치를 찾는다.
c를 찾으면 c의 위치를 주소를 반환하고
찾지못하면 NULL을 반환한다.
* s가 ""이고 c가

- ft_strnstr
char *ft_strnstr(const char *big, const char *little, size_t len)
이 함수는 big 문자열에 len 길이 중에서 little 문자열을 찾는 것이다.
만약 little 값이 비어 있으면 big를 반환한다.
big 문자열에서 little 문자열을 찾지 못하면 NULL을 반환한다.
little 문자열을 찾으면 big에 little 문자열 시작 부분 위치 주소를 반환한다.
(검색에서 마지막 NULL 문자는 포함하지 않는다)
* return ((char *)&big[i]) : big[i]는 주솟값이 아니기 때문에 형 변환시 &을 넣어주어야 한다

- ft_strncmp
int ft_strncmp(const char* str1, const char* str2, size_t n);
str1과 str2를 n까지 비교하여 같으면 0 다르면 음수나 양수를 출력한다.
* 의문점 : unsigned char로의 형변환하는 코드가 필요한지?
* 해결 : 128 이상의 ascii code 수도 계산하기 위해서 형변환이 필요 ( ft_Strncmp("test\200", "test\0", 6)같은 128이상의 ascii code 문제 해결 필요 )

- ft_atoi
int ft_atoi(const char *str)
문자열을 정수로 변환(문자열에서 첫번째로 나타나는 비-공백 문자가 숫자 혹은 +, -가 아니라면 어떠한 변환도 이루어지지 않는데 또한 문자열이 공백문자로만 이루어져 있어도 변환이 이루어지지 않는다)(변환이 이루어지지 않는 경우 0이 리턴된다 ex)a123)

- ft_memset
void	*ft_memset(void *dst, int c, size_t n)
dst 위치부터, n개의 바이트 만큼, c 라는 값으로 초기화 하는 함수
* unsigned char로 사용하는 이유 : unsigned char는 모든 bit를 투명하게 볼수 있음(다른 type은 내부비트의 일부를 값을 표현하기 위한 용도가 아닌 다른 용도(부호 비트)로 사용할수 있으나 unsigned char는 이것이 안됨)
* 이러한 이유로 표준이 바이트 값에 접근해야 하는 경우나 문자에 접근해야 하는 경우 (ex : mem(), str() 함수들)에는 모두 unsigned char로 접근하도록 요구
* byte 단위로 초기화하기 때문에 int형 배열을 초기화 할때 주의하기 : 1byte당 1로 초기화 된 것이기 때문에 1로 초기화가 안된다 (가능한 수 : 0, -1)

- ft_bzero
void	ft_bzero(void *b, size_t n)
b 위치부터, n개의 바이트 만큼 0으로 초기화 하는 함수.(더 이상 사용되지 않는 함수, memset 사용하기)

- ft_memcpy
void	*ft_memcpy(void *dst, const void *src, size_t n)
src가 가리키는 곳부터 n바이트 만큼을 dst가 가리키는 곳에 복사한다
src의 null 종료 문자를 검사하지 않는다(정확히 n바이트 만큼을 복사)
const void *src를 함수 내에서 unsigned char * 로 강제 형변환을 하려고 하면 경고 뜸
const unsigned char * 로 형변환 해줘야 함