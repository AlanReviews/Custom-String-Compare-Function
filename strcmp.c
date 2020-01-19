#include <stdio.h>

#define NULL_TERMINATOR  (0x00)
#define MIN(a, b) ((a) < (b)) ? (a) : (b)

int stringcompare(const char *s1, const char *s2) {
    // Handle null cases
    if ((s1 == NULL) && (s2 == NULL)) {
        return 0;
    }
    else if ((s1 == NULL) && (s2 != NULL)) {
        return -1;
    }
    else if ((s1 != NULL) && (s2 == NULL)) {
        return 1;
    }
    // Handle non-null cases
    int minSize = MIN(sizeof(s1), sizeof(s2));
    // Iterate to the earlier terminator
    for (int i = 0; i < minSize + 1; i++) {
        if (s1[i] != s2[i]) {
            return (s1[i] - s2[i]);
        }
    }

    return 0;
}

int main() {
    printf("%d\n", stringcompare("run", "home"));
    printf("%d\n", stringcompare("alan", "alan"));
    printf("%d\n", stringcompare("gfg", "gfn"));
    printf("%d\n", stringcompare("run", "run1"));
    printf("%d\n", stringcompare("al", "a"));
    printf("%d\n", stringcompare(NULL, "a"));
    printf("%d\n", stringcompare("a", NULL));
    printf("%d\n", stringcompare(NULL, NULL));

    return 0;
}