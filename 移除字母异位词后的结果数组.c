

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool issame(char *s, char *p){ // 判断是否是字母异位词
    if(strlen(s) != strlen(p)){
        return false;
    }
    int map[26] = {0};
    for(int i = 0; i < strlen(s); i++){
        map[s[i]-'a']++;
    }
    for(int i = 0; i < strlen(p); i++){
        if(map[p[i]-'a'] > 0){
            map[p[i]-'a']--;
        }else{
            return false;
        }
    }
    return true;
}
char ** removeAnagrams(char ** words, int wordsSize, int* returnSize){
    char **ans = malloc(sizeof(char*)*wordsSize);
    for(int i = 0; i < wordsSize; i++){
        ans[i] = malloc(sizeof(char)*11);
    }
    int k = 0;
    *returnSize = 0;
    strcpy(ans[(*returnSize)++],words[0]);
    for(int i = 1; i < wordsSize; i++){
        if(issame(words[i],words[i-1])){
            continue;
        }else{
            strcpy(ans[(*returnSize)++],words[i]);
        }
    }
    return ans;
}