# void pointer

> reference :
1. [(c언어) void 포인터 개념과 자유로운 형변환](https://reakwon.tistory.com/19)

---

포인터는 특정 메모리 주소값을 가리킨다. 해당 메모리에 int형 값이 올라가 있다면 그 포인터는 `int *`이 되겠고, char형 값이 올라가 있다면 `char *`가 된다.  그리고 만약 해당 메모리에 어떤 자료형이 올라가 있는지 모른다면 이 때 `void *`가 되는 것이다.

void pointer는 자료형을 모르는 상태이므로 포인터연산이 불가하다.
즉,

```c
#include <stdio.h>

int main()
{
	void *b;
	int	i;

	i = 10;
	b = &i;
	printf("%d\n", *b);
}
```
위 코드를 실행하면 아래와 같은 에러를 발생시킨다.

```
Error:Expression must be a pointer to a complete object type
```

따라서 포인터 연산이 필요하다면 `int *`로 형변환을 해주면 된다.

```c
#include <stdio.h>

int main()
{
	void *b;
	int	i;

	i = 10;
	b = &i;
	printf("%d\n", *(int *)b);
}
```

```
10
```
