#include <stdio.h>
#include <stdlib.h>

int main(void){
    // 임의의 포인터 선언
    int *list;
    // int 3개짜리 메모리 공간 할당
    list = malloc(sizeof(int)*3);
    // 메모리 공간이 제대로 할당되지 않은 경우(메모리 부족) list는 NULL
    if (list == NULL){
        return 1;
    } else { // 정상적으로 malloc을 통해 메모리 공간을 받았다면 메모리 공간에 int 채워넣음
    list[0] = 0;
    list[1] = 1;
    list[2] = 2;
    }

    // for-loop을 위한 임의의 변수 선언
    int i;
    for (i=0;i<3;i++){ // list 내 모든 int 출력
        printf("%i\n", *(list+i));
    }

    // int 하나 추가하기 위해 12bit -> 16bit 메모리로 변경하고자 함
    // 임의의 포인터 선언
    int *tmp;
    // 메모리 공간을 malloc처럼 할당(sizeof(int)*4)하면서
    // 다른 메모리 공간(list)에서 데이터를 가져옴
    tmp = realloc(list, sizeof(int)*4);
    if (tmp == NULL){
        return 1;
    } else {
        tmp[3] = 3; // 남은 마지막 메모리 공간에 int 3 채워넣음
        list = tmp; // 동일한 주소를 가리킨다.
    }

    int j;
    for (j=0;j<4;j++){
        printf("%i\n", *(list+j));
    }
    free(list);
    free(tmp); 
    printf("%p\n", tmp);
    printf("%p\n", list);
    printf("%i\n", *(tmp+1)); // 위에서 free로 메모리 해제해줬기 때문에 에러 발생 
    printf("%i\n", *(list+1)); // list와 tmp 중 하나라도 해제하지 않는다면 둘 다 출력 가능(동일한 주소를 가리키므로) 
    return 0;
}
