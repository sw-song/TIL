#include <stdio.h>
#include <stdlib.h>

// binary tree 구조체 선언
typedef struct node {
    int number;
    //검색하는 숫자가 현재 노드의 number 보다 작다면 이동할 노드를 가리키는 포인터
    struct node *left; 
    //검색하는 숫자가 현재 노드의 number 보다 크다면 이동할 노드를 가리키는 포인터
    struct node *right;
} node; // alias


// binary search function
int search(node *tree, int i){
    if (tree==NULL){
        printf("%i is not exist in tree\n", i);
        return 0;
    }
    else if (i < (*tree).number){
        // 재귀 -> 검색하는 숫자가 현재 노드의 number 보다 작다면 left 노드로 이동하여 검색
        return search((*tree).left,i);
    }
    else if (i > (*tree).number){
        // 재귀 -> 검색하는 숫자가 현재 노드의 number 보다 크다면 right 노드로 이동하여 검색
        return search((*tree).right,i);
    }
    else{
        printf("%i is in tree\n", i);
        return 0;
    }
}

int f_malloc(node **tree){
    if (*tree==NULL){
        printf("트리가 더 이상 없습니다.\n");
        return 2;
    } 
    else if ((*tree)->left==NULL && (*tree)->right==NULL){
        free((*tree));
        printf("하위 노드가 없습니다. 현재 노드 메모리를 해제합니다.\n");
        (*tree) = NULL; // 메모리를 해제해줘도 변수가 가리키는 주소는 남는다. 주소를 NULL로 지정한다.
        return 0; 
    }
    else if ((*tree)->left==NULL && (*tree)->right!=NULL){
        printf("오른쪽 아래 노드만 존재합니다. 오른쪽 아래 노드로 이동합니다\n");
        return f_malloc(&((*tree)->right));
    }
    else if ((*tree)->left!=NULL && (*tree)->right==NULL){
        printf("왼쪽 아래 노드만 존재합니다. 왼쪽 아래 노드로 이동합니다\n");
        return f_malloc(&((*tree)->left));
    }
    else if ((*tree)->left!=NULL && (*tree)->right!=NULL){
        printf("하위 노드가 2개 모두 존재합니다. 왼쪽 노드로 이동합니다\n");
        return f_malloc(&((*tree)->left));
    } else{
        printf("잘못된 참조입니다\n");
        return 1;
    }
    return 0;
}

int main(void){
    node *list;
    list = NULL;

    node *n;
    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 5;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드 할당(number=5)
    list=n;

    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 3;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드(number=5) 아래의 left 노드 할당(number=3)
    list->left = n;

    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 7;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드(number=5) 아래의 right 노드 할당(number=7)
    list->right = n;

    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 2;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드(number=5) 아래 left 노드(number=3) 아래 left 노드 할당(number=2)
    list->left->left = n;

    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 4;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드(number=5) 아래 left 노드(number=3) 아래 right 노드 할당(number=4)
    list->left->right = n;

    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 6;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드(number=5) 아래 right 노드(number=7) 아래 left 노드 할당(number=6)
    list->right->left = n;

    n = malloc(sizeof(node));
    if(n != NULL){
        n->number = 8;
        n->left = NULL;
        n->right = NULL;
    }
    // 루트 노드(number=5) 아래 right 노드(number=7) 아래 right 노드 할당(number=8)
    list->right->right = n;

    
    int t;
    for (t=0;t<10;t++){
        search(list, t);
    }
   
    int a;
    a = 0;
    int count;
    count = 0;
    while(a==0){
        printf(">> 메모리 해제 중.. \n");
        a = f_malloc(&list);
        count++;
        if (a!=2){
            printf(">> 끝에서 %i번째 노드 메모리가 해제되었습니다\n", count);
        } else {
            printf(">> 모든 노드의 메모리가 해제되었습니다\n");
        }
    }

    return 0;
        
    
}
