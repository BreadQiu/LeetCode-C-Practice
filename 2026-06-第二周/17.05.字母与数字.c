/**
*题目：字母与数字
*日期：2026.6.12
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findLongestSubarray(char** array, int arraySize, int* returnSize) {
    int cnt[200001]={0};
    int start=0,end=0;
    for(int tmp=0,i=0;i<arraySize;i++){
        tmp+='A'<=array[i][0]&&array[i][0]<='Z'||'a'<=array[i][0]&&array[i][0]<='z'?1:-1;
        if(!tmp){
            start=0,end=i;
        }else if(!cnt[tmp+100000]){
            cnt[tmp+100000]=i+1;
        }else if(i-cnt[tmp+100000]>end-start){
            start=cnt[tmp+100000],end=i;
        }
    }
    if(start==0&&end==0){
        *returnSize=0;
        return NULL;
    }
    *returnSize=end-start+1;
    char**ret=(char**)malloc((*returnSize)*sizeof(char*));
    for(int i=0;i<=end-start;i++){
        ret[i]=(char*)malloc((strlen(array[i+start])+1)*sizeof(char));
        strcpy(ret[i],array[i+start]);
    }
    return ret;
}
