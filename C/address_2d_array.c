#include <stdio.h>

int main(void){
    int arr[2][3];

    printf("%p\n", arr);
    printf("%p\n", arr[0]);
    printf("%sp\n", &arr[0][0]);
}
