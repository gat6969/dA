#include <stdio.h>

int w[10], p[10], n;

int max(int a, int b) {
    return a > b ? a : b;
}

int knapsack(int i, int cap) {
    if (i == n) return 0;
    if (w[i] > cap) return knapsack(i + 1, cap);
    return max(knapsack(i + 1, cap), knapsack(i + 1, cap - w[i]) + p[i]);
}

int main() {
    int cap;
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &cap);
    printf("Enter profit and weight for each item:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i], &w[i]);

    printf("Max profit = %d\n", knapsack(0, cap));
    return 0;
}
