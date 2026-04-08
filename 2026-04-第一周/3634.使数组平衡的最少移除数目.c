/**
*题目：使数组平衡的最少移除数目
*日期：2026.4.4
*/
int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int minRemoval(int* nums, int numsSize, int k) {
    if(numsSize==1) return 0;
    int left,right,min=INT_MAX;
    qsort(nums,numsSize,sizeof(int),cmp);
    for(left=0,right=numsSize-1;nums[left]<nums[right]/(double)k;++left);
    min=fmin(left+numsSize-1-right,min);
    for(--right;right>=0;--right){
        for(;left>=0&&nums[left]>=nums[right]/(double)k;--left);
        ++left;
        min=fmin(left+numsSize-1-right,min);
        if(left==0) break;
    }
    if(min==INT_MAX) return 0;
    return min;
}
