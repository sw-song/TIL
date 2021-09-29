#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int number;
    struct node *next;
} node;


int main(void){

    // node 구조체를 가리키는 포인터 n을 선언
    node *n;
    // n은 node 구조체를 가리키므로 node의 메모리 크기(int + pointer to int) 즉 8+8만큼 메모리 할당
    n = malloc(sizeof(node));

    // n이 가리키는 주소(node 구조체) 출력
    printf("%p\n", n);
    // n의 메모리 크기(포인터이므로 8bit)
    printf("%lu\n", sizeof(n));
    // 구조체 node의 메모리 크기(16bit)
    printf("%lu\n", sizeof(node));

    if (n != NULL){ // 정상적으로 메모리가 할당(malloc 사용)되었다면,,
        // n이 가리키는 node 구조체에 접근(*)해서 해당 구조체의 number변수에 값 할당
        (*n).number = 2; // n->number = 2 로 사용 가능 | -> 는 포인터로 구조체 내부 변수에 접근하도록 하는 문 
        (*n).next = NULL; // 아직 구조체 1개로 존재. next가 또 다른 구조체 node를 가르키도록 주소를 할당해주면 linked list가 됨
    }
    printf("%i\n", (*n).number); // 2
    printf("%p\n", (*n).next); // 0x0(16진수 0) 은 앞에서 NULL을 할당해줘서 그럼. 어떤 주소도 가르키지 않는 포인터를 뜻함.   



    free(n);
    return 0;
}

