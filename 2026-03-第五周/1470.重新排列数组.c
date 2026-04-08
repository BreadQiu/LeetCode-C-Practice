/**
*题目：重新排列数组
*日期：2026.3.31
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
    int i;
    *returnSize=numsSize;
    int* new=(int*)malloc(2*n*sizeof(int));
    for(i=0;i<n;++i) if(i<n) new[2*i]=nums[i];
    for(;i<2*n;++i) new[(i-n)*2+1] =nums[i];
    return new;
}
