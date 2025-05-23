#include <stdio.h>
#include <string.h>
#define MAX 256

void createShiftTable(char *pat, int m, int shift[]) {
    for (int i = 0; i < MAX; i++) shift[i] = m;
    for (int i = 0; i < m - 1; i++)
        shift[(unsigned char)pat[i]] = m - 1 - i;
}

int horspoolMatching(char *txt, char *pat) {
    int n = strlen(txt), m = strlen(pat), shift[MAX];
    createShiftTable(pat, m, shift);
    int i = m - 1;
    while (i < n) {
        int k = 0;
        while (k < m && pat[m - 1 - k] == txt[i - k]) k++;
        if (k == m) return i - m + 1;
        i += shift[(unsigned char)txt[i]];
    }
    return -1;
}

int main() {
    char txt[100], pat[50];
    printf("Enter the text: ");
    fgets(txt, sizeof(txt), stdin);
    txt[strcspn(txt, "\n")] = '\0';
    printf("Enter the pattern: ");
    fgets(pat, sizeof(pat), stdin);
    pat[strcspn(pat, "\n")] = '\0';
    
    int pos = horspoolMatching(txt, pat);
    if (pos != -1)
        printf("Pattern found at position: %d\n", pos);
    else
        printf("Pattern not found in the text.\n");
    return 0;
}
