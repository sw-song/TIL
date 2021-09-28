#include <stdio.h>

int main(void){
    int arr[2][3];

    printf("%p\n", arr);
    printf("%p\n", &arr[0]);
    printf("%p\n", arr[0]);
    printf("%p\n", &arr[0][0]);

    // 위 출력 값은 모두 동일하다
    // arr은 arr[0]의 주소, arr[0]은 arr[0][0]의 주소
    return 0;
}
