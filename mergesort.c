#include <stdio.h>
int count;

void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = l, b[10];
    while (i <= m && j <= r) {
        count++;
        b[k++] = (a[i] < a[j]) ? a[i++] : a[j++];
    }
    while (i <= m) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; i++)
     a[i] = b[i];
}

void mergesort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main() {
    int a[10], n;
    printf("Enter no of elements: ");
    scanf("%d", &n);
    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
     scanf("%d", &a[i]);
    mergesort(a, 0, n - 1);
    printf("Sorted elements:\n");
    for (int i = 0; i < n; i++) 
    printf("%d\n", a[i]);
    printf("Count: %d\n", count);
    return 0;
}
