bool checkAlmostEquivalent(char * word1, char * word2){

    int m[30] = {0};
    int n[30] = {0};

    for(int i = 0 ; i < strlen(word1) ; i++)
    {
        m[word1[i] - 97]++;
        n[word2[i] - 97]++;
    }
    for(int i = 0 ; i < 30 ; i++)
    {
        if(m[i] - n[i] > 3 || n[i] - m[i] > 3)
        {
            return false;
        }
    }
    return true;
}