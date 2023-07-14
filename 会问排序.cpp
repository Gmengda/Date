bool canPermutePalindrome(char* s){
    int a[128] = {0};
    int i, cnt = 0, len = strlen(s);

    for (i = 0; i < len; i++)
        a[s[i]]++;

    for (i = 0; i < 128; i++) {
        if (a[i]%2 == 1)
            cnt++;
        if (cnt >= 2)
            return false;
    }

    return true;
}