bool halvesAreAlike(char * s) {
    int len = strlen(s);
    char *h = "aeiouAEIOU";
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < len / 2; i++) {
        if (strchr(h, s[i])) {
            sum1++;
        }
    }
    for (int i = len / 2 ; i < len; i++) {
        if (strchr(h, s[i])) {
            sum2++;
        }
    }
    return sum1 == sum2;
}