/* Prasannaa.V, CH.SC.U4CSE24138 */

#include <stdio.h>
#include <stdlib.h>

void bucketSort(int arr[], int n) {
    int max = arr[0];

    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];

    int bucketCount = max + 1;

    int *bucket = (int *)calloc(bucketCount, sizeof(int));

    for (int i = 0; i < n; i++)
        bucket[arr[i]]++;

    int index = 0;
    for (int i = 0; i < bucketCount; i++) {
        while (bucket[i] > 0) {
            arr[index++] = i;
            bucket[i]--;
        }
    }

    free(bucket);
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    bucketSort(arr, n);

    printf("Sorted output: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

