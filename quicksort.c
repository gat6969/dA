#include <stdio.h>
int count;

int partition(int a[], int low, int high) {
    int i = low + 1, j = high, pivot = a[low], temp;
    while (1) {
        while (i <= high && pivot >= a[i]) { i++; count++; }
        count++;
        while (j >= low && pivot < a[j]) { j--; count++; }
        count++;
        if (i < j) {
            temp = a[i];
             a[i] = a[j];
              a[j] = temp;
        } else {
            temp = a[low];
             a[low] = a[j];
              a[j] = temp;
            return j;
        }
    }
}

void quicksort(int a[], int low, int high) {
    if (low < high) {
        int j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}

int main() {
    int a[10], n;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 1; i <= n; i++)
     scanf("%d", &a[i]);
    quicksort(a, 1, n);
    printf("Sorted elements:\n");
    for (int i = 1; i <= n; i++) 
    printf("%d ", a[i]);
    printf("\nCount: %d\n", count);
    return 0;
}
