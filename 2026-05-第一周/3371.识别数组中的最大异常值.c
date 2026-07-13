/**
*题目：识别数组中的最大异常值
*日期：2026.5.4
*/
int cmp(const void*a,const void*b){
    return *(int*)a-*(int*)b;
}

int getLargestOutlier(int* nums, int numsSize) {
    qsort(nums,numsSize,sizeof(int),cmp);
    int sum=0;
    int cnt[2001]={0};
    for(int i=0;i<numsSize;i++){
        sum+=nums[i];
        cnt[nums[i]+1000]++;
    }
    for(int i=numsSize-1;i>=0;i--){
        cnt[nums[i]+1000]--;
        if((sum-nums[i])%2==0&&sum-nums[i]>=-2000&&sum-nums[i]<=2000&&cnt[(sum-nums[i])/2+1000]>0) return nums[i];
        cnt[nums[i]+1000]++;
    }
    return -1;
}
