#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
} node;

int main(void){
    // 노드 포인터 선언 (linked list의 첫번째 노드를 가리킬 포인터)
    node *list;
    // 우선, 아무것도 가리키지 않도록 NULL주소 할당
    list = NULL;

    printf("%p\n", list); // 출력해보면 0x0 반환(16진수 0)

    //-----------------------------------------------------------//
    // 노드 포인터 만들기
    // 노드 포인터 *list를 선언한 것처럼 *n을 선언함.
    // n은 임시 포인터로, 중간에서 연결선을 만들고 빠지는 역할
    // 굳이 왜 이렇게 하냐면, 이후 이 코드를 반복문 안에서 사용하면 긴 linked list를 한번에 만들 수 있기 때문
    node *n;
    n = malloc(sizeof(node));
    if (n != NULL){ // 제대로 메모리가 할당되었다면 계속,,
        (*n).number = 1; // n이 가리키는 노드에 접근(*) 하여 접근한 노드 내 변수 number에 1 할당
        (*n).next = NULL; // n이 가리키는 노드에 접근(*) 하여 접근한 노드 내 노드포인터 next에 NULL 할당(일단, 아무 주소도 가리키지 않도록)
    }

    //------------------------------------------------------------//
    // 이제 임시 노드 포인터 *n로 만들어준 '노드(number = 1, next = NULL)'를 *list 노드 포인터가 가리키도록 주소값을 복사한다
    list = n;

    printf("%p\n", list); 
    printf("%p\n", n); //list와 같은 주소를 가리킨다. 같은 값을 반환.
    printf("%i\n", list->number); // (*list).number와 같은 문법이다. // 1
    printf("%i\n", n->number); // 1
    printf("%p\n", list->next); // 0x0
    printf("%p\n", n->next); // 0x0


    //------------------------------------------------------------//
    // 임시 노드 포인터 *n 재활용(다음 노드 생성)
    n = malloc(sizeof(node));
    if (n != NULL){
        (*n).number = 2;
        (*n).next = NULL;
    }
    
    //------------------------------------------------------------//
    // 이제 임시 노드 포인터 *n로 만들어준 '노드(number = 2, next = NULL)'를 *list 가 가리키는 노드 내 *next 노드 포인터가 가리키도록 주소값을 복사한다.
    (*list).next = n;

    printf("%i\n", (*list).number); // 1 : 첫번째 노드의 number
    printf("%i\n", list->number); // 1 : 윗줄과 같은 문법
    printf("%i\n", (*(*list).next).number); // 2 : 두번째 노드의 number // list->next
    printf("%i\n", list->next->number); // 2 : 윗줄과 같은 문법

    //------------------------------------------------------------//
    // 임시 노드 포인터 *n 재활용(다음 노드 생성)
    n = malloc(sizeof(node));
    if (n != NULL){
        (*n).number = 3;
        (*n).next = NULL;
    }
    //------------------------------------------------------------//
    // 이제 임시 노드 포인터 *n로 만들어준 '노드(number = 3, next = NULL)'를 2번째 노드의 next가 가리키도록 주소값을 복사한다.
    (*(*list).next).next = n; // list->next->next = n; 과 같은 코드
    
    printf("%i\n", list->number); // 1
    printf("%i\n", list->next->number); // 2
    printf("%i\n", list->next->next->number); // 3
    //------------------------------------------------------------//
    // for문을 돌면서 linked list의 number값을 모두 출력할 수도 있다.
    node *tmp; // 변수(노드 포인터)를 수정하면서 출력하기 때문에 임시 변수를 선언한다.
    
    // 입력1-선언) 첫번째 노드 주소를 가리키도록 링크드리스트 첫번째 노드 주소값 할당하고 for문 시작
    // 입력2-조건) 다음 노드를 가리키는 포인터가 NULL(0x0을 가리킴)이 아니라면(다음 노드 존재) 반복 
    // 입력3-연산) tmp에 다음 노드를 가리키는 포인터 할당
    for (tmp = list; tmp != NULL; tmp = tmp->next){
        printf("%i\n", (*tmp).number); // tmp가 가리키는 노드로 접근(*)해서 해당 노드 내 number 출력
    }

    // -----------------------------------------------------------//
    // 종료하기 전에 동적으로 할당한 모든 메모리를 해제한다.
    // free(list);
    // free(list->next);
    // free(list->next->next);
    // 위 코드를 while 루프를 통해 구현하는데,
    // 하나의 임시 변수 주소값을 참조시키면서 메모리를 해제할 것이다. 
    node *tmp2; // 구조체 노드를 가리키는 포인터 선언(주소값을 참조시킬 변수)
    while (list != NULL){
        tmp2 = list->next; // 2번째(반복문의 반복-현재시점) 포인터를 미리 임시 포인터에 복사(참조)한다.
        free(list); // 링크드리스트의 첫번째 노드(반복문의 반복-현재 시점)가 차지한 메모리를 할당 해제한다.
        list = tmp2; // list는 원래 가리키던 다음 노드의 포인터가 된다. (가장 앞의 포인터 해제)
    }

    return 0;
}
