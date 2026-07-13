/**
*题目：特殊数组 II
*日期：2026.5.10
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* isArraySpecial(int* nums, int numsSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize) {
    int*s=(int*)malloc((numsSize+1)*sizeof(int));
    s[0]=0;
    for(int i=1;i<numsSize;i++){
        if((nums[i]+nums[i-1])&1) s[i]=s[i-1];
        else s[i]=i;
    }
    bool*ret=(bool*)malloc(queriesSize*sizeof(bool));
    for(int i=0;i<queriesSize;i++){
        ret[i]=(s[queries[i][0]]==s[queries[i][1]])?true:false;
    }
    *returnSize=queriesSize;
    return ret;
}
