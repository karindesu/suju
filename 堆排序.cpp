#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}
void max_heapify(int arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son])
            return;
        else {
            swap(&arr[dad], &arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}
void heap_sort(int arr[], int len) {
    int i,j;
    for (i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
            for (j = 0; j < len; j++)
        printf("%d ", arr[j]);
            printf("\n");
    for (i = len - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        max_heapify(arr, 0, i - 1);
                    for (j = 0; j < len; j++)
        printf("%d ", arr[j]);
             printf("\n");
    }
}
int main() {
    int arr[10] ={6, 12, 458, 5, 4, 28, 19, 1230, 9, 47};
    int len = 10;
    heap_sort(arr, len);
    int i;
    for (i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
