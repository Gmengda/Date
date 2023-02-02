#include <stdio.h>
#include <stdlib.h>

char findTheDifference(char* s, char* t) {
    int n = strlen(s), m = strlen(t);
    int ret = 0;
    for (int i = 0; i < n; i++) {
        ret ^= s[i];
    }
    for (int i = 0; i < m; i++) {
        ret ^= t[i];
    }
    return ret;
}