/**
*题目：统计特殊三元组
*日期：2026.5.4
*/
int specialTriplets(int* nums, int numsSize) {
    long long*cntLeft=(long long*)calloc(100001,sizeof(long long));
    long long*cntRight=(long long*)calloc(100001,sizeof(long long));
    for(int i=numsSize-1;i>=2;i--){
        cntRight[nums[i]]++;
    }
    cntLeft[nums[0]]++;
    long long ret=0;
    for(int i=1;i<numsSize-1;i++){
        if(nums[i]<=50000) ret+=cntLeft[nums[i]*2]*cntRight[nums[i]*2];
        cntLeft[nums[i]]++;
        cntRight[nums[i+1]]--;
    }
    return ret%1000000007;
}
