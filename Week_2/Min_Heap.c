/* Prasannaa.V, CH.SC.U4CSE24138 */

#include <stdio.h>
#include<stdlib.h>


#define MAX 100

int heap[MAX];
int heapSize = 0;

// Swap helper
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify DOWN (used after deletion)
void heapifyDown(int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < heapSize && heap[left] < heap[smallest])
        smallest = left;

    if (right < heapSize && heap[right] < heap[smallest])
        smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapifyDown(smallest);
    }
}


// Heapify UP (used after insertion)
void heapifyUp(int index) {
    int parent = (index - 1) / 2;

    if (index > 0 && heap[index] < heap[parent]) {
        swap(&heap[index], &heap[parent]);
        heapifyUp(parent);
    }
}

// INSERT into Min Heap
void insert(int value) {
    heap[heapSize] = value;
    heapifyUp(heapSize);
    heapSize++;
}

// DELETE MIN (extract root)
int extractMin() {
    if (heapSize <= 0) {
        printf("Heap is empty!\n");
        return -1;
    }

    int minValue = heap[0];

    heap[0] = heap[heapSize - 1];
    heapSize--;

    heapifyDown(0);

    return minValue;
}

// DISPLAY HEAP
void displayHeap() {
    printf("Min Heap: ");
    for (int i = 0; i < heapSize; i++) {
        printf("%d ", heap[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n---- MIN HEAP MENU ----\n");
        printf("1. Insert\n");
        printf("2. Extract Min\n");
        printf("3. Display Heap\n");
        printf("4. Exit\n");
        printf("Choose: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                printf("Min removed = %d\n", extractMin());
                break;

            case 3:
                displayHeap();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
}
