char * frequencySort(char * s){
    int len = strlen(s);
    if (len <= 2)
        return s;
    int count[128] = {0}; 
    for (int i = 0 ; i < len ; i++) 
    {
        count[s[i]]++;
    }
    
    int cmp(const void *p1, const void *p2) 
    {
        char c1 = *(char*)p1;
        char c2 = *(char*)p2;
        return count[c1] == count[c2] ?  c1 > c2 : count[c1] < count[c2]; 
    }

    qsort(s, len, sizeof(char), cmp);
    return s;
}