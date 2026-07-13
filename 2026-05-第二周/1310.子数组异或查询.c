/**
*题目：子数组异或查询
*日期：2026.5.10
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int*s=(int*)malloc((arrSize+1)*sizeof(int));
    s[0]=0;
    for(int i=1;i<=arrSize;i++){
        s[i]=s[i-1]^arr[i-1];
    }
    int*ret=(int*)malloc(queriesSize*sizeof(int));
    for(int i=0;i<queriesSize;i++){
        ret[i]=s[queries[i][1]+1]^s[queries[i][0]];
    }
    *returnSize=queriesSize;
    return ret;
}
