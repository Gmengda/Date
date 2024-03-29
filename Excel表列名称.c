void reverse(char* str, int strSize) {
    int left = 0, right = strSize - 1;
    while (left < right) {
        char tmp = str[left];
        str[left] = str[right], str[right] = tmp;
        left++;
        right--;
    }
}

char* convertToTitle(int columnNumber) {
    char* ans = malloc(sizeof(char) * 8);
    int ansSize = 0;
    while (columnNumber > 0) {
        int a0 = (columnNumber - 1) % 26 + 1;
        ans[ansSize++] = a0 - 1 + 'A';
        columnNumber = (columnNumber - a0) / 26;
    }
    ans[ansSize] = '\0';
    reverse(ans, ansSize);
    return ans;
}