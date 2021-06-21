## ft_printf

**서브젝트 보면서 Exteranl functs 에서 `va_start` `va_arg` `va_copy` `va_end` 가 있는데 이게 뭐인지 부터 알아야 할꺼 같다.**
일단 찾아보니 저것들을 가변인수라고 한다.

**프로토 타입은`int	ft_printf(const char *format, ...)` ...  은 가변인자가 몇개가 될지 모르기 때문에 저렇게 표시함. 자유롭게 지정할수 있다는걸 나타내기도 함.** 
**여기서 인수의 취득에는 `va_start`, `va_arg`,`va_end` 3개의 매크로 함수를 사용. 이 함수를 사용하려면 `stdarg.h` 헤더 파일을 포함 해야함.**

1. `va_list`
	**각 가변 인자의 시작 주소를 가리킬 포인터**. 내부적으로는 `char *`로 정의 되 었다.
2. `va_start`
	`va_list`로 만들어진 포인터에게 **가변인자 중 첫번째 인자의 주소를 가르쳐주는** 매크로다.
	`#define va_start(ap, v) ((ap) = (va_list)_ADDRESSOF(v) + _INTSIZEOF(v))` 이렇게 생겼다.
3. `va_arg`
	특정 가변인자를 가리키고 있는 **`va_list`의 포인터를 다음 가변인자로 이동**시켜 주는 매크로.
	`#define_crt_va_arg(ap,t) (*(t *)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))`
	매크로의 첫 번째 인자로 **`va_list`로 만든 포인터**가 담기고,
	매크로의 두 번째 인자로 **타입 이름**이 담긴다.(int, long, double 등)
	*char, short 의 경우에는 int로 대신 쓰고, float의 경우에는 double로 대신 쓴 이후 형변환을 해줘야한다. ex)`char ch = (char)va_arg(ap,int);`*
4. `va_end`
	가변인자를 끝내는 역할. 단순히 보면 NULL 포인터로 돌려주는 매크로. 
	`#define_crt_va_end(ap) (ap = (va_list)0)`
	매크로의 인자로 **`va_list`로 만든 포인터**가 담긴다.

**만들어야 하는 서식 지정자**
`c s p d i u x X %`
1.	`c` 정수를 문자.
2.	`s` 정수를 문자열.
3.	`p` 값을 16진수 8자리
4.	`d` 부호가 있는 10진수 정수
5.	`i` 부호가 있는 10진수 정수
6.	`u` 부호가 없는 10진수 정수
7.	`x` 부호가 없는 16진수 정수, 영어 알파벳 소문자 사용
8.	`X` 부호가 없는 16진수 정수, 영어 알파벳 대문자 사용
9.	`%` % 문자 출력
**서식문자에서 사용되는 플래그**
`- 0 . *`