#include <stdio.h>
#include <stdlib.h>
int minSwapsToSort(int* arr, int n) {
    int swapCount = 0,temp,i,j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCount += 1;
            }
        }
    }
    return swapCount;
}

int main() {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int res = minSwapsToSort(arr, n);
    printf("%d\n", res);
    free(arr);
    return 0;
}
