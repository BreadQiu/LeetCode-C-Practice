/**
*题目：统计坏数对的数目
*日期：2026.5.4
*/
long long countBadPairs(int* nums, int numsSize) {
    int*cnt=(int*)calloc(1000100002,sizeof(int));
    long long ret=0;
    for(int i=0;i<numsSize;i++){
        ret+=cnt[nums[i]-i+100000];
        cnt[nums[i]-i+100000]++;
    }
    return numsSize*(numsSize-1L)/2-ret;
}
