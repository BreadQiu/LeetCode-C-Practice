/**
*题目：统计美丽子数组数目
*日期：2026.6.12
*/
long long beautifulSubarrays(int* nums, int numsSize) {
    int cnt[1048576]={0};
    int tmp=0;
    cnt[0]++;
    long long ret=0;
    for(int i=0;i<numsSize;i++){
        tmp=tmp^nums[i];
        cnt[tmp]++;
        ret+=cnt[tmp]-1;
    }
    return ret;
}
