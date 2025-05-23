#include <stdio.h>
#include <string.h>

void search(const char* pat, const char* txt) {
    int m = strlen(pat), n = strlen(txt);
    for (int i = 0; i <= n - m; i++) {
        if (strncmp(txt + i, pat, m) == 0)
            printf("Pattern found at index %d\n", i);
    }
}

int main() {
    search("AABA", "AABAACAADAABAAABAA");
    return 0;
}
