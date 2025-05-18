
#include "main.h"
// int main(int argc,char *argv[]){

//     int numlist[] = {0,1,9,3,4};
//     int result;
    
    
//     result = lis(numlist,5);
//     printf("\n%d\n",result);
//     return 0;

// }
// #include <stdio.h>
// #include <stdlib.h>

// int lis(int *numbox, int size); // 関数のプロトタイプ宣言

// int main(void) {
//     int arr1[] = {10, 22, 9, 33, 21, 50, 41, 60};
//     int arr2[] = {3, 10, 2, 1, 20};
//     int arr3[] = {3, 2};
//     int arr4[] = {1, 2, 3, 4, 5};
//     int arr5[] = {5, 4, 3, 2, 1};

//     printf("LIS length (arr1): %d\n", lis(arr1, sizeof(arr1)/sizeof(int))); // → 5
//     printf("LIS length (arr2): %d\n", lis(arr2, sizeof(arr2)/sizeof(int))); // → 3
//     printf("LIS length (arr3): %d\n", lis(arr3, sizeof(arr3)/sizeof(int))); // → 1
//     printf("LIS length (arr4): %d\n", lis(arr4, sizeof(arr4)/sizeof(int))); // → 5
//     printf("LIS length (arr5): %d\n", lis(arr5, sizeof(arr5)/sizeof(int))); // → 1

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

int *lis(int *numbox, int size);

void print_lis(int *lis_result) {
    int i = 0;
    printf("LIS: ");
    while (lis_result[i] != -1) {
        printf("%d ", lis_result[i]);
        i++;
    }
    printf("\n");
}

int main(void) {
    int arr1[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int arr2[] = {3, 10, 2, 1, 20};
    int arr3[] = {3, 2};
    int arr4[] = {1, 2, 3, 4, 5};
    int arr5[] = {5, 4, 3, 2, 1};

    // print_lis(lis(arr1, sizeof(arr1) / sizeof(int)));
    // print_lis(lis(arr2, sizeof(arr2) / sizeof(int)));
    // print_lis(lis(arr3, sizeof(arr3) / sizeof(int)));
    print_lis(lis(arr4, sizeof(arr4) / sizeof(int)));
    //print_lis(lis(arr5, sizeof(arr5) / sizeof(int)));

    return 0;
}

