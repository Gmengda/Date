typedef struct{
	int val;
	int index;
}st;
int cmp(const void* a, const void* b){
	return ((st*)a)->val - ((st*)b)->val;
}
int* arrayRankTransform(int* arr, int arrSize, int* returnSize){
	st* stArr = (st*)calloc(arrSize,sizeof(st));
	int i,j=0;
	for (i=0; i<arrSize; i++) {
        stArr[i].index = i;
        stArr[i].val = arr[i];
    }
	qsort(stArr,arrSize,sizeof(st),cmp);
	for(i=0; i<arrSize; i++){
        arr[stArr[i].index] = (i && stArr[i].val == stArr[i-1].val)? j: ++j;
    } 
	*returnSize = arrSize;
	return arr;
}