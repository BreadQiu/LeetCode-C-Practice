/**
*题目：半径为 k 的子数组平均值
*日期：2026.3.25
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getAverages(int* nums, int numsSize, int k, int* returnSize) {
    int *avg=(int*)malloc(numsSize*sizeof(int));
    int i;
    long long sum=0;
    returnSize[0]=numsSize;
    if(numsSize<2*k+1){
        for(i=0;i<numsSize;++i) avg[i]=-1;
        return avg;
    }
    for(i=0;i<k;++i){
        sum+=nums[i];
        avg[i]=-1;
    }
    for(;i<2*k;++i) sum+=nums[i];
    for(;i<numsSize;++i){
        sum+=nums[i];
        avg[i-k]=sum/(2*k+1);
        sum-=nums[i-2*k];
    }
    for(;i<numsSize+k;i++) avg[i-k]=-1;
    return avg;
}
