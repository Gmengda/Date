int* bit;

int cmp(void* _x, void* _y) {
    int x = *(int*)_x, y = *(int*)_y;
    return bit[x] == bit[y] ? x - y : bit[x] - bit[y];
}

int* sortByBits(int* arr, int arrSize, int* returnSize) {
    bit = malloc(sizeof(int) * 10001);
    memset(bit, 0, sizeof(int) * 10001);
    for (int i = 1; i <= 10000; ++i) {
        bit[i] = bit[i >> 1] + (i & 1);
    }
    qsort(arr, arrSize, sizeof(int), cmp);
    free(bit);
    *returnSize = arrSize;
    return arr;
}